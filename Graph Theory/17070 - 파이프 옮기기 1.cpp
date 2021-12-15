#include<iostream>
#include<queue>
using namespace std;

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
