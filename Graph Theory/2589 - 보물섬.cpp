#include<iostream>
#include<queue>
using namespace std;

int M, N;

string treasure_map[50];

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

inline bool is_in_scope(int i, int j) {
	if (0 <= i && i < M && 0 <= j && j < N) {
		return true;
	}
	else {
		return false;
	}
}

int bfs(int start_i, int start_j) {
	int time;

	queue<vector<int>> bfs_queue;

	int is_visited[50][50] = { 0, };

	bfs_queue.push({ start_i, start_j, 0 });
	is_visited[start_i][start_j] = 1;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		bfs_queue.pop();
		time = cur_depth;


		for (int i = 0;i < 4;i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (is_in_scope(next_i, next_j) && is_visited[next_i][next_j] == 0 && treasure_map[next_i][next_j] == 'L') {
				is_visited[next_i][next_j] = 1;
				bfs_queue.push({ next_i, next_j, cur_depth + 1 });
			}
		}
	}

	return time;
}


int solution() {
	int answer = 0;

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (treasure_map[i][j] == 'L') {
				answer = max(answer, bfs(i, j));
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0;i < M;i++) {
		cin >> treasure_map[i];
	}

	cout << solution() << '\n';
}
