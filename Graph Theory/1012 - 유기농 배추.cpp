#include<iostream>
#include<queue>
using namespace std;

int M, N, K;
int cabbage_field[50][50] = { {0,} }; // 배추밭을 표현한 배열

//         아래, 위, 오른쪽, 왼쪽
int di[4] = { +1, -1,  0,  0 };
int dj[4] = { 0,  0, +1, -1 };

void bfs(vector<int> start_node) {
	queue<vector<int>> bfs_queue;

	// 첫 위치 큐에 푸시
	bfs_queue.push(start_node);

	// 첫 시작 위치 방문표시해주기
	cabbage_field[start_node[0]][start_node[1]] = 0;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];

		bfs_queue.pop();

		// 아래, 위, 오른쪽, 왼쪽 순으로 탐색 진행
		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			// 다음 노드가 범위 내일 경우에만 진행
			if (0 <= next_i && next_i < M && 0 <= next_j && next_j < N) {
				// 다음 노드가 배추가 있는 노드일 경우에만 큐에 push하며 방문 표시
				if (cabbage_field[next_i][next_j] == 1) {
					// 중복 방문 방지를 위해 미리 방문 표시
					cabbage_field[next_i][next_j] = 0;
					// 방문 예정 노드 큐에 푸시
					bfs_queue.push({ next_i, next_j });
				}
			}
		}
	}
	
}

int solution() {
	int answer = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			// 배추가 있을 경우에만 BFS 진행
			if (cabbage_field[i][j] == 1) {
				answer++; // 하나의 배추 모임이 더 있는 것이므로 흰지렁이 마리 수 추가
				bfs({ i, j });
			}
		}
	}

	return answer;
}

int main() {
	int T;
	int X, Y;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			cabbage_field[X][Y] = 1;
		}
		cout<< solution() << '\n';
	}
}
