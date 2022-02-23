#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 미로의 세로 길이
M: 미로의 가로 길이

- 변수 제한 사항
N, M: 1~100

각 방의 상태: 1 = 벽 / 0 = 빈 방

- 문제 상황
 미로의 상태가 주어질 때, (1, 1)부터 (N, M)까지 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하여라

2. 풀이 계획
 벽을 최소 몇개 부수어야 하는지에 대한 문제이므로, 벽이 부서질 때만 비용이 발생한다고 보면 된다.

 따라서 0 - 1 BFS라고 볼 수 있다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int N, M;
string maze[100];

inline bool isInRange(int i, int j) {
	return (0 <= i && i < N && 0 <= j && j < M);
}

int solution() {
	vector<vector<int>> numOfWalls(N, vector<int>(M, 100 * 100));

	numOfWalls[0][0] = 0;

	deque<pair<int,int>>bfs_queue;

	bfs_queue.push_back({ 0, 0 });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop_front();

		if (cur_i == N - 1 && cur_j == M - 1) {
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j)) {
				if (maze[next_i][next_j] == '1') {
					if (numOfWalls[cur_i][cur_j] + 1 < numOfWalls[next_i][next_j]) {
						numOfWalls[next_i][next_j] = numOfWalls[cur_i][cur_j] + 1;
						bfs_queue.push_back({ next_i, next_j });
					}
				}
				else {
					if (numOfWalls[cur_i][cur_j] < numOfWalls[next_i][next_j]) {
						numOfWalls[next_i][next_j] = numOfWalls[cur_i][cur_j];
						bfs_queue.push_front({ next_i, next_j });
					}
				}
			}
		}
	}

	return numOfWalls[N - 1][M - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}

	cout << solution();

	return 0;
}