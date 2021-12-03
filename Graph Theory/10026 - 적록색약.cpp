#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 그림의 세로 밑 가로 길이

- 변수 제한 사항
N: 1~100

- 문제 상황
적록색약은 빨간색과 초록색을 구분하지 못한다.

그림이 주어질 때 적록색약이 보는 구역의 수와 아닌 사람이 보는 구역의 수를 각각 구하라

2. 풀이 계획
 영역이 어떻게 되는지 알기 위해서는 한 부분당 한번의 탐색만 있으면 되고, 각각의 이동에 가중치가 없으므로,

방문 표시를 미리하고 탐색을 진행하는 BFS를 통해 풀 수 있는 문제처럼 보인다!

따라서 적록 색약일 때와 아닐때에 대해 각각 모든 아직 방문하지 않은 위치에서의 bfs를 진행하면 될 듯 하다!

3. 계획 검증

*/

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