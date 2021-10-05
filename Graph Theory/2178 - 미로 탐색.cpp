#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string>
using namespace std;

int N, M;

// 미로를 입력받기 위한 배열
vector<string> maze;

// 4방향 이동을 나타내기 위한 배열
//         down,right,up,left 
int di[4] = { 0, +1, 0, -1 };
int dj[4] = { +1, 0, -1, 0 };

int answer = 2000; // 모든 칸을 방문하여도 1000


int solution(int start_i, int start_j) {
	queue<vector<int>> bfs_queue; // 방문할 좌표와 그 깊이를 같이 가지고 있는 큐
	
	bfs_queue.push({ start_i, start_j, 1 }); // 첫 좌표 푸시

	maze[start_i][start_j] = '0'; // 현재노드 방문했다는 표시하기

	while (!bfs_queue.empty()) {

		vector<int> cur_node = bfs_queue.front();
		bfs_queue.pop();
		int cur_i = cur_node[0]; // i 좌표
		int cur_j = cur_node[1]; // j 좌표
		int cur_depth = cur_node[2]; // 그래프의 깊이(시작점부터의 거리)

		if (cur_i == N && cur_j == M) {
			return cur_depth;
		}

		// 아래, 오른쪽, 위, 왼쪽 순으로 탐색
		// 갈 수 있는 방향인 1이 있는 방향으로만 탐색
		for (int i = 0; i < 4; i++) {
			if (maze[cur_i + di[i]][cur_j + dj[i]] == '1') { // 갈 수 있는 곳일 경우
				maze[cur_i + di[i]][cur_j + dj[i]] = '0'; // 중복 방문 방지를 위해 미리 방문 표시하기
				bfs_queue.push({ cur_i + di[i], cur_j + dj[i], cur_depth + 1 }); // 좌표 정보와 거리 정보 푸시
			}
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;

	string maze_row; // 미로의 각 한 행을 만들기

	string wall = ""; // 위와 아래 벽 만들기
	for (int i = 0; i < M + 2; i++) {
		wall += "0";
	}

	maze.push_back(wall); // 미로의 위 벽 표시

	for (int i = 0; i < N; i++) {
		cin >> maze_row;
		maze.push_back("0" + maze_row + "0"); // 왼쪽과 오른쪽 벽을 붙여서 입력
	}

	maze.push_back(wall); // 미로의 아래쪽 벽 표시

	// 벽을 위치시켰으므로 (0, 0)이 아닌 (1, 1) 위치부터 시작
	// 지나간 칸 수를 세는 것이므로 현재 칸도 포함시켜 1부터 시작
	cout<< solution(1, 1);

	return 0;
}
