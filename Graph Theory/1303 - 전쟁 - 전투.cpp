#include<iostream>
#include<queue>
using namespace std;

#define MAX 100

int n, m;
char war[MAX][MAX];
bool isVisited[MAX][MAX];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int isInRange(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int bfs(int start_i, int start_j, char side) {
	int power = 0;

	queue<pair<int, int>> bfs_queue;

	isVisited[start_i][start_j] = true;
	bfs_queue.push({ start_i, start_j });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();
		power++;

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (!isInRange(next_i, next_j) || isVisited[next_i][next_j]) continue;

			if (war[next_i][next_j] == side) {
				isVisited[next_i][next_j] = true;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}

	return power * power;
}

void solution() {
	int friendly_power = 0;
	int enemy_power = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isVisited[i][j] == false) {
				if (war[i][j] == 'W') friendly_power += bfs(i, j, 'W');
				else enemy_power += bfs(i, j, 'B');
			}
		}
	}

	cout << friendly_power << ' ';
	cout << enemy_power;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> war[i][j];
		}
	}

	solution();

	return 0;
}
