#include<iostream>
#include<queue>
using namespace std;

int tomato_box[1000][1000];
int M, N;

//         아래, 위, 오른쪽, 왼쪽
int di[4] = { +1, -1,   0,  0 };
int dj[4] = {  0,  0,  +1, -1};


int solution() {
	int answer = 0;
	// BFS를 진행하기 위한 큐
	queue<vector<int>> bfs_queue; 
	
	// 각 시작점(처음에 존재하는 익은 토마토)을 큐에 푸시
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato_box[i][j] == 1) {
				bfs_queue.push({ i, j, 0 });
			}
		}
	}

	// 토마토 익히는 과정
	while (!bfs_queue.empty()) {
		// 현재 노드 가져오기
		vector<int> cur_node;
		cur_node = bfs_queue.front();
		bfs_queue.pop();
		answer = cur_node[2]; // 현재 갈 수 있는 곳 중 가장 깊이가 얕은(거리가 가까운) 노드부터 방문하므로, 항상 깊이가 익는데 걸리는 기간이 됨!

		for (int j = 0; j < 4; j++) {
			// 다음에 진행할 노드의 좌표정보
			int cur_i = cur_node[0] + di[j];
			int cur_j = cur_node[1] + dj[j];
			if (0 <= cur_i && cur_i < N && 0 <= cur_j && cur_j < M) { // 범위 내 값일 때만 진행
				if (tomato_box[cur_i][cur_j] == 0) {
					tomato_box[cur_i][cur_j] = 1; // 중복 방문 방지를 위해 익었다는 표시 미리 해놓기
					bfs_queue.push({ cur_i, cur_j, cur_node[2] + 1 }); 
				}
			}
		}
	}

	// 안익은 토마토가 아직 남았다면 -1반환
	for (int i = 0;i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato_box[i][j] == 0) {
				return -1;
			}
		}
	}

	// 모두 익었다면 최소 날짜 반환
	return answer;
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato_box[i][j];
		}
	}

	cout << solution();
}
