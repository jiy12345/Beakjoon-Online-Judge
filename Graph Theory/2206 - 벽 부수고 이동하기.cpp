#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
