#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 체스판의 세로, 가로 길이

 - 변수 제한 사항
N: 5 ~ 200
체스판의 행과 열은 0부터 시작

- 문제 상황
데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동한다.

체스판의 두 위치가 주어질 때, 첫번째 위치에서 두번째 위치로 이동하는 최소 이동 회수를 구하여라

데스나이트는 체스판 밖으로 벗어날 수 없다.

2. 풀이 계획
 벽을 최소 몇개 부수어야 하는지에 대한 문제이므로, 벽이 부서질 때만 비용이 발생한다고 보면 된다.

 따라서 0 - 1 BFS라고 볼 수 있다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int dr[6] = { -2, -2, 0, 0, +2, +2 };
int dc[6] = { -1, +1, -2, +2, -1, +1 };

int N;
bool isVisited[200][200];
int r1, c1, r2, c2;

bool isInRange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int solution() {
	int answer = -1;

	queue<pair<int, pair<int, int>>> bfs_queue;

	bfs_queue.push({ 0, {r1, c1} });
	isVisited[r1][c1] = true;

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front().first;
		int cur_r = bfs_queue.front().second.first;
		int cur_c = bfs_queue.front().second.second;
		bfs_queue.pop();

		if (cur_r == r2 && cur_c == c2) {
			answer = cur_depth;
			break;
		}

		for (int i = 0; i < 6; i++) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];

			if (isInRange(next_r, next_c) && isVisited[next_r][next_c] == false) {
				isVisited[next_r][next_c] = true;
				bfs_queue.push({ cur_depth + 1, {next_r, next_c} });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	cin >> r1 >> c1 >> r2 >> c2;

	cout << solution();

	return 0;
}
