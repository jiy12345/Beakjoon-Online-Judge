#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

string picture[100];
int is_visited[100][100];

int N;

void bfs(int start_i, int start_j, vector<char> cur_color) {
	queue<pair<int, int>> bfs_queue;

	bfs_queue.push({ start_i, start_j });
	is_visited[start_i][start_j] = true;

	while (!bfs_queue.empty()) {
		pair<int, int> cur_node = bfs_queue.front();;
		bfs_queue.pop();

		int cur_i = cur_node.first;
		int cur_j = cur_node.second;


		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			if (0 <= next_i && next_i < N && 0 <= next_j && next_j < N) {
				// 방문하지 않았고, 같은 색일때만 push
				if (is_visited[next_i][next_j] == 0 && find(cur_color.begin(), cur_color.end(), picture[next_i][next_j]) != cur_color.end()) {
					is_visited[next_i][next_j] = 1;
					bfs_queue.push({ next_i, next_j });
				}
			}
		}
	}
}

void solution() {
	// 정상적인 사람의 경우
	int normal_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_visited[i][j] == 0) {
				normal_cnt++;
				bfs(i, j, { picture[i][j] });
			}
		}
	}

	memset(is_visited, 0, sizeof(is_visited));

	// 적록 색약이 있는 사람의 경우
	int rg_weakness_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_visited[i][j] == 0) {
				rg_weakness_cnt++;
				if (picture[i][j] == 'R' || picture[i][j] == 'G') {
					bfs(i, j, { 'R', 'G'});
				}
				else {
					bfs(i, j, { 'B' });
				}
			}
		}
	}

	cout << normal_cnt << " " << rg_weakness_cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> picture[i];
	}

	solution();
}
