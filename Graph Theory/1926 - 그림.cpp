#include<iostream>
#include<queue>
using namespace std;

#define MAX 500

int n, m;
int drawingPaper[MAX][MAX];
bool isVisited[MAX][MAX];
int numOfPaintings;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int isInRange(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int bfs(int start_i, int start_j) {
	numOfPaintings++;

	int area = 0;

	queue<pair<int, int>> bfs_queue;

	isVisited[start_i][start_j] = true;
	bfs_queue.push({ start_i, start_j });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();
		area++;
		
		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (!isInRange(next_i, next_j) || isVisited[next_i][next_j]) continue;

			if (drawingPaper[next_i][next_j] == 1) {
				isVisited[next_i][next_j] = true;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}

	return area;
}

void solution() {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (drawingPaper[i][j] == 1 && isVisited[i][j] == false) answer = max(answer, bfs(i, j));
		}
	}

	cout << numOfPaintings << '\n';
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> drawingPaper[i][j];
		}
	}

	solution();

	return 0;
}
