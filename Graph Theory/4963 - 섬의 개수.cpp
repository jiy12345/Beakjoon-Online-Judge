#include<iostream>
#include<queue>
using namespace std;

int dx[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };

void bfs(int map[][52], pair<int, int> start_node) {
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(start_node);

	while (!bfs_queue.empty()) {
		pair<int, int> cur_node = bfs_queue.front();
		bfs_queue.pop();

		// 8 방향에 대해 모두 체크
		for (int i = 0;i < 8;i++) {
			int cur_x = cur_node.first + dx[i];
			int cur_y = cur_node.second + dy[i];

			// 이미 탐색한 노드 표시
			if (map[cur_x][cur_y] == 1) {
				map[cur_x][cur_y] = 0;
				bfs_queue.push({ cur_x, cur_y });
			}
		}
	}
}

int solution(int map[][52], int w, int h) {
	int cnt = 0;

	// 모든 노드에 대해 탐색
	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			// 각 노드가 육지일 경우
			if (map[i][j] == 1) {
				// 섬의 개수 1 더해주기
				cnt++;
				// 해당 노드로부터 탐색할 수 있는 육지 bfs로 탐색
				bfs(map, { i, j });
			}
		}
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int w, h;
	while (true) {
		cin >> w >> h;

		// 종ㅇ료 조건
		if (w == 0 && h == 0) {
			break;
		}

		int map[52][52];

		for (int i = 1;i <= h;i++) {
			for (int j = 1;j <= w;j++) {
				cin >> map[i][j];
			}
		}

		cout << solution(map, w, h) << "\n";
	}

	return 0;
}
