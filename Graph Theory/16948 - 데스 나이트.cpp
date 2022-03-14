#include<iostream>
#include<queue>
using namespace std;

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
