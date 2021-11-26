#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 맵의 세로 길이
M: 맵의 가로 길이

- 변수 제한 사항
N, M: 1~1,000

- 문제 상황
 한개의 벽을 부수고 이동할 수 있다고 할 떄, 최단 거리를 출력한다.

불가능하다면 -1을 출력한다.

2. 풀이 계획
 1000 * 1000이면 일반적인 DFS를 진행하여서는 시간초과가 날만한 크기이다. 따라서 BFS를 진행해야 할 듯 하다.

 그런데 BFS를 진행할 때 큐에 푸시할 때 방문 표시를 하여 중복방문이 안되기 한다면 괜찮나?

 해당 위치까지 최단거리라고 보장할 수 있나?
  => 일단 뚫는다고 가정하기 때문에

  뚫는 것을 표시해줘도 방문표시를 먼저 해버린다면 해당 경로가 막혀서 더이상 갈 수 없는 경우가 되었을 경우에는 경로가 있음에도 경로를 찾지 못하는 경우가 발생할 수도 있다!

  => 그렇다면 뚫은 다음의 경우에는 방문 표시를 진행하지 않는다면 어떨까?
  => 그런데 이렇게 한다면 4방향 이동이기 때문에 계속해서 이동만 하는 경우가 발생할 수 있다!
*/

int N, M;

int dx[4] = { 0,  0, 1, -1 };
int dy[4] = { 1, -1, 0,  0 };

string map[1000];
// 뚫었을 때와 뚫지 않았을 때의 경로를 따로 계산하기 위해 3차원으로 저장
int depth[1000][1000][2];

int solution() {
	int answer = -1;

	// 좌표, 남은 뚫는 기회의 수 저장
	queue<vector<int>> bfs_queue;
	
	bfs_queue.push({ 0,0,1 });

	depth[0][0][1] = 1; // 첫 위치까지의 이동은 1로 간주

	while (!bfs_queue.empty()) {
		int cur_x = bfs_queue.front()[0];
		int cur_y = bfs_queue.front()[1];
		int block_num = bfs_queue.front()[2];
		bfs_queue.pop();

		cout << "cur_x: " << cur_x << ", cur_y: " << cur_y << endl;;

		if (cur_x == N - 1 && cur_y == M - 1) {
			answer = depth[cur_x][cur_y][block_num];
			break;
		}

		for (int i = 0;i < 4;i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				// 갈 수없는 길(벽)이고, 벽을 아직 안뚫었을때
				if (map[next_x][next_y] == '1' && block_num == 1) {
					depth[next_x][next_y][block_num - 1] = depth[cur_x][cur_y][block_num] + 1;
					bfs_queue.push({ next_x, next_y, block_num - 1 });
				}
				// 갈 수있는 길이고, 방문하지 않았다면
				if (map[next_x][next_y] == '0' && depth[next_x][next_y][block_num] == 0) {
					depth[next_x][next_y][block_num] = depth[cur_x][cur_y][block_num] + 1;
					bfs_queue.push({ next_x, next_y, block_num });
				}
			}
		}
	}

	return answer;
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> map[i];
	}

	cout << solution();
}