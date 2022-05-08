#include<iostream>
#include<vector>
#include<deque>
using namespace std;

#define MAX 50

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int n;
string maze[MAX];

inline bool isInRange(int i, int j) {
	return (0 <= i && i < n && 0 <= j && j < n);
}

int solution() {
	vector<vector<int>> numOfWalls(n, vector<int>(MAX * MAX, MAX * MAX));

	numOfWalls[0][0] = 0;

	deque<pair<int, int>>bfs_queue;

	bfs_queue.push_back({ 0, 0 });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop_front();

		if (cur_i == n - 1 && cur_j == n - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j)) {
				if (maze[next_i][next_j] == '0') {
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

	return numOfWalls[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	cout << solution();

	return 0;
}
