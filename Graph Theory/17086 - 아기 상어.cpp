﻿#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
K: 말을 따라할 수 있는 횟수
W, H: 격자판의 가로길이, 세로길이​

- 변수 제한 사항
K: 0 ~ 30
W, H: 1 ~ 200​

0: 평지
1: 장애물

- 문제 상황

2. 풀이 계획​

3. 계획 검증
 1. 알고리즘 측면​

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define MAX 50

int di[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };

int N, M;
int grid[MAX][MAX];
int dist[MAX][MAX];

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

void bfs(vector<pair<int, int>> shark_loc) {
	queue<vector<int>> bfs_queue;

	for (pair<int, int> shark:shark_loc) {
		bfs_queue.push({ 0, shark.first, shark.second });
	}

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front()[0];
		int cur_i = bfs_queue.front()[1];
		int cur_j = bfs_queue.front()[2];
		bfs_queue.pop();

		for (int i = 0; i < 8; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j) == true && dist[next_i][next_j] == 0) {
				dist[next_i][next_j] = cur_depth + 1;
				bfs_queue.push({ cur_depth + 1, next_i, next_j });
			}
		}
	}
}

int solution(vector<pair<int, int>> shark_loc) {
	int answer = 0;
	bfs(shark_loc);

	for (int i = 0; i < N; i++) {
		answer = max(answer, *max_element(dist[i], dist[i] + M));
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	vector <pair<int, int>> shark_loc;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 1) {
				shark_loc.push_back({ i, j });
				dist[i][j] = 1;
			}
		}

	cout << solution(shark_loc);
}