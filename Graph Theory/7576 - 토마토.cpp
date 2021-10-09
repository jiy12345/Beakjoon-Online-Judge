#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
M, N: 토마토 상자의 가로, 세로 크기

- 변수 제한 사항
M, N : 2~1,000

 => 토마토 상자배열의 각 값의 의미
1: 익은 토마토
0: 익지 않은 토마토
-1: 비어있는 부분

- 문제 상황
 익은 토마토는 상, 하, 좌, 우의 익지 않은 토마토를 익히며, 하루마다 한번씩 익은 토마토가 주변의 토마토를 익힌다.
이때 토마토가 모두 익을때까지 걸리는 최소 날짜를 출력하라.
=> 모든 토마토가 익지 못하는 상황이라면 -1을 출력한다.

2. 풀이 계획
 토마토가 익는 것은 모든 곳에서 동시에 진행된다. 
 따라서 첫 날 존재하는 각각의 익은 토마토에 대해 BFS 탐색을 제외하고, 해당 토마토에 갈 수 있는 안익은 토마토가 없을 경우 각각의 탐색을 먼저 끝내면 될듯 하다.
 그렇게 하였을 때 마지막으로 종료되는 BFS 탐색의 깊이가 전체 토마토가 익는 최소 날짜라고 보면 될듯 하다.
 이 때 마지막에 전체 배열에 0이 아직 남아있다면 -1을 출력하고, 그렇지 않다면 구한 최소 날짜를 출력하면 될듯 하다!

따라서 자세한 계획은 다음과 같다.

1. 토마토 상자의 정보를 -1로 둘러싸 입력받는다.
2. 토마토 상자에서 현재 익은 토마토의 위치들을 모두 찾고, 해당 위치에 대해 각각 BFS를 진행한다.
 => BFS 큐를 각 익은 토마토의 위치별로 만든다!
3. 가장 오랫동안 탐색이 진행된 BFS의 깊이를 일단 최소 날짜로 저장한다.
4. 마지막으로 상자 배열을 탐색하여 0이 남았을 경우 모든 토마토가 익지 않은 것이므로 -1을 출력하고, 그렇지 않으면 0을 출력한다.

3. 계획 검증

 - 시간복잡도 측면:

 - 공간복잡도 측면: 1,000 x 1,000 = 4,000,000

*/

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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tomato_box[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	bool is_unripe_tomato = false;

	for (int i = 0;i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato_box[i][j] == 0) {
				is_unripe_tomato = true;
			}
		}
	}

	if (is_unripe_tomato == true) {
		return -1;
	}
	else {
		return answer;
	}
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