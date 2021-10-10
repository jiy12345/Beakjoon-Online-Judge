#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
M, N: 배추밭의 가로길이, 세로길이
K: 배추가 심어져 있는 위치의 개수
X, Y: 배추의 위치를 표현하는 좌표

- 변수 제한 사항
M, N: 1~50
K: 1~M*N

두 배추의 위치가 같은 경우는 없다.

- 문제 상황
 상하좌우 네 방향에 다른 배추가 위치한 경우 서로 인접해있다고 볼 때, 배추 흰지렁이는 인접한 배추들간에는 이동하여 해충을 제거할 수 있다.

이 때 주어진 밭의 조건에 총 몇마리의 배추흰지렁이가 필요한지 구하라.

2. 풀이 계획
중복없이 방문하는 BFS를 진행하면 될 것 같고, 딱히 최단거리 등을 구하는 것이 아니므로 굳이 깊이를 잴 필요는 없을듯 하다.

따라서 자세한 계획은 다음과 같다.

1. 2차원 배열에 각 배추의 위치를 1로, 배추가 없는 위치는 0으로 하여 입력받는다.
2. 배추밭의 모든 위치를 탐색하며, 배추가 있는 위치에 대해서만 BFS를 진행한다.
 => 이 때 BFS로 탐색한 위치는 0으로 표시를 바꾼다.
3. BFS가 진행된 횟수를 세 출력한다.

3. 계획 검증


*/

int M, N, K;
int cabbage_field[50][50] = { {0,} }; // 배추밭을 표현한 배열

//         아래, 위, 오른쪽, 왼쪽
int di[4] = { +1, -1,  0,  0 };
int dj[4] = { 0,  0, +1, -1 };

void bfs(vector<int> start_node) {
	queue<vector<int>> bfs_queue;

	bfs_queue.push(start_node);

	cabbage_field[start_node[0]][start_node[1]] = 0;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];

		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			// 다음 노드가 범위 내일 경우에만 진행
			if (0 <= next_i && next_i < M && 0 <= next_j && next_j < N) {
				// 다음 노드가 배추가 있는 노드일 경우에만 큐에 push하며 방문 표시
				if (cabbage_field[next_i][next_j] == 1) {
					cabbage_field[next_i][next_j] = 0;
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

				cout << endl;
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