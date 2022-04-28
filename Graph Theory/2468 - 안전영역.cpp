#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int region[102][102];
int N;

// region: 각 위치가 안전영역이면 true, 아니면 false
void bfs(int cur_region[102][102], pair<int, int> cur_loc, int water_level) {
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(cur_loc);

	while (!bfs_queue.empty()) {
		pair<int, int>loc = bfs_queue.front();
		bfs_queue.pop();

		for (int i = 0;i < 4;i++) {
			int cur_i = loc.first - dx[i];
			int cur_j = loc.second - dy[i];

			if (cur_region[cur_i][cur_j] - water_level > 0) {
				// 더 이상 탐색하지 않도록 가장 낮은 높이로 설정
				cur_region[cur_i][cur_j] = 0;
				bfs_queue.push({ cur_i, cur_j });
			}
		}
	}
}

int find_safe_zone(int cur_region[102][102], int water_level) {
	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			// 현 위치가 침수되지 않은 위치라면
			if (cur_region[i][j] - water_level > 0) {
				cnt++;
				// 현 위치부터 vfs 시작
				bfs(cur_region, { i,j }, water_level);
			}
		}
	}
	return cnt;
}

int solution(int max_num) {
	int answer = 0;

	// 각각의 모든 높이에 대해서 체크
	for (int i = 0;i <= max_num;i++) {
		int cur_region[102][102];
		copy(&region[0][0], &region[0][0] + 102 * 102 , &cur_region[0][0]);
		answer = max(answer, find_safe_zone(cur_region, i));
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	int max_num = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> region[i][j];
			max_num = max(max_num, region[i][j]);
		}
	}

	cout << solution(max_num);

	return 0;
}
