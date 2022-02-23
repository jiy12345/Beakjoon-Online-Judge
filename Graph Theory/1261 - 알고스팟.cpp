#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
