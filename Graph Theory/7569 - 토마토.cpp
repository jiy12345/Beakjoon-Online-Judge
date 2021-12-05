#include<iostream>
#include<queue>
using namespace std;

int tomato_box[100][100][100];
int M, N, H;

//           뒤  앞  오른 왼  아래 위
int di[6] = { +1, -1,  0,  0,  0,  0 };
int dj[6] = {  0,  0, +1, -1,  0,  0 };
int dk[6] = {  0,  0,  0,  0, +1, -1 };

int solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int answer = 0;
	// BFS를 진행하기 위한 큐
	queue<vector<int>> bfs_queue;

	// 각 시작점(처음에 존재하는 익은 토마토)을 큐에 푸시
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0;k < H;k++) {
				if (tomato_box[i][j][k] == 1) {
					bfs_queue.push({ i, j, k, 0 });
				}
			}
		}
	}

	// 토마토 익히는 과정
	while (!bfs_queue.empty()) {
		// 현재 노드 가져오기
		vector<int> cur_node;
		cur_node = bfs_queue.front();
		bfs_queue.pop();
		answer = cur_node[3]; // 현재 갈 수 있는 곳 중 가장 깊이가 얕은(거리가 가까운) 노드부터 방문하므로, 항상 깊이가 익는데 걸리는 기간이 됨!

		for (int j = 0; j < 6; j++) {
			// 다음에 진행할 노드의 좌표정보
			int next_i = cur_node[0] + di[j];
			int next_j = cur_node[1] + dj[j];
			int next_k = cur_node[2] + dk[j];
			if (0 <= next_i && next_i < N && 0 <= next_j && next_j < M && 0 <= next_k && next_k < H) { // 범위 내 값일 때만 진행
				if (tomato_box[next_i][next_j][next_k] == 0) {
					tomato_box[next_i][next_j][next_k] = 1; // 중복 방문 방지를 위해 익었다는 표시 미리 해놓기
					bfs_queue.push({ next_i, next_j, next_k, cur_node[3] + 1 });
				}
			}
		}
	}

	// 안익은 토마토가 아직 남았다면 -1반환
	for (int k = 0;k < H;k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tomato_box[i][j][k] == 0) {
					return -1;
				}
			}
		}
	}

	// 모두 익었다면 최소 날짜 반환
	return answer;
}

int main() {
	cin >> M >> N >> H;
	for (int k = 0;k < H;k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tomato_box[i][j][k];
			}
		}
	}

	cout << solution();
}