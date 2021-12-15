#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 격자판의 가로, 세로길이

- 변수 제한 사항
 N: 3~16
 각 위치의 수: 1 = 벽, 0 = 빈칸

- 문제 상황
파이프가 가능한 방향은 3가지이며, 파이프가 각 방향일 때 이동 가능한 방향은 다음과 같다고 할 때,

가로: 우측, 우하단
세로: 하단, 우하단
대각선: 하단, 우하단, 우측

파이프가 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.

2. 풀이 계획
 이동시킬 수 있는 방법의 수를 구하는 것이므로, DFS를 시도하거나, pop할 때 방문표시를 하는 BFS를 시도해야 할 듯 하다!

=> 파이프가 좌측으로 이동하거나 회전할 일이 있다면 좌측 끝 좌표도 의미가 있겠지만, 이 문제에서는 파이프가 우측, 하단, 우하단으로만 이동하므로, 아래쪽 끝이나 우측 끝 좌표와 회전 상태만 가지고 있으면 될듯 하다!

파이프의 오른쪽 끝의 좌표와 현재 파이프의 방향을 알고 있어야 할 듯 하다!

따라서 현 회전 상태에 따라 가능한 방향의 위치를 큐에 푸시하며 bfs를 진행하면 될 듯 하다!

이 문제는 방문 표시를 아예 하지 않아야 맞다!

=> 대각선 이동이 세로 이동으로 해야할 경로를 먼저 막아버릴수도 있기 때문이다!

*/

enum laidState {
	HORIZONTAL,
	VERTICAL,
	DIAGONAL
};

int N;

bool map[18][18];

int solution() {
	int num_of_route = 0;

	// 0, 1: 현재 위치의 좌표
	// 2: 현재 파이프의 방향
	// 0
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ 1, 2, HORIZONTAL });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_laidState = bfs_queue.front()[2];
		bfs_queue.pop();

		if (cur_i == N && cur_j == N) {
			num_of_route++;
		}

		// 1. 가로로 놓여있을 경우
		if (cur_laidState == HORIZONTAL) {
			// 1) 우측 이동
			if (map[cur_i][cur_j + 1] == 0) {
				bfs_queue.push({ cur_i, cur_j + 1, HORIZONTAL });
			}
			// 2) 우하단 이동
			if (map[cur_i + 1][cur_j + 1] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j + 1, DIAGONAL });
			}
		}		
		// 2. 세로로 놓여있을 경우
		if (cur_laidState == VERTICAL) {
			// 1) 하단이동 이동
			if (map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j, VERTICAL });
			}
			// 2) 우하단 이동
			if (map[cur_i + 1][cur_j + 1] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j + 1, DIAGONAL });
			}
		}		
		// 3. 대각선으로 놓여있을 경우
		if (cur_laidState == DIAGONAL) {
			// 1) 우측 이동
			if (map[cur_i][cur_j + 1] == 0) {
				bfs_queue.push({ cur_i, cur_j + 1, HORIZONTAL });
			}
			// 2) 하단 이동
			if (map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j, VERTICAL });
			}
			// 3) 우하단 이동
			if (map[cur_i + 1][cur_j + 1] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j + 1, DIAGONAL });
			}
		}
	}

	return num_of_route;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i <= N + 1;i++) {
		
		for (int j = 0;j <= N + 1;j++) {
			// 외부 경계 만들어주기
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				map[i][j] = 1;
			}
			else {
				cin >> map[i][j];
			}
		}
	}

	cout << solution();
}