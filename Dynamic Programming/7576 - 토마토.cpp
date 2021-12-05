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
	// 각 익은 토마토에 대한 BFS 큐를 가지고 있는 배열
	// 각 큐는 다음 탐색할 좌표값과 깊이값을 가지고 있음
	queue<vector<int>> bfs_queue; 
	
	// 각 시작점에 대한 bfs 큐 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato_box[i][j] == 1) {
				bfs_queue.push({ i, j, 0 });
			}
		}
	}

	while (!bfs_queue.empty()) {
		vector<int> cur_node;
		cur_node = bfs_queue.front();
		bfs_queue.pop();
		answer = cur_node[2]; // 각각의 노드 중 가장 깊은 값이 답이 됨

		for (int j = 0; j < 4; j++) {
			int cur_i = cur_node[0] + di[j];
			int cur_j = cur_node[1] + dj[j];
			if (0 <= cur_i && cur_i < N && 0 <= cur_j && cur_j < M) { // 범위 내 값일 때만 진행
				if (tomato_box[cur_i][cur_j] == 0) {
					tomato_box[cur_i][cur_j] = 1; // 익었다는 표시 미리 해놓기
					bfs_queue.push({ cur_i, cur_j, cur_node[2] + 1 });
				}
			}
		}
	}

	for (int i = 0;i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato_box[i][j] == 0) {
		        return -1;
			}
		}
	}

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
