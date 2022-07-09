#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
M, N: 성의 가로, 세로 길이

- 변수 제한 사항
 N, M: 1~50

- 문제 상황
 성의 지도가 주어졌을 때, 

 1. 이 성에 있는 방의 개수
 2. 가장 넓은 방의 넓이
 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
 
 를 구하여라.

2. 풀이 계획​

 1. 이 성에 있는 방의 개수
각각의 방마다 bfs를 진행하며 방문 표시를 하고, 번호를 매기며 방의 개수를 세면 될 듯 하다.

 2. 가장 넓은 방의 넓이
bfs를 진행하며 각각의 방의 넓이를 기록해두고, 그 중 가장 큰 값을 찾으면 될 듯 하다.

 3. 하나의
각 방에 대한 bfs를 진행하며 해당 방이 어떤 방과 벽을 두고 접하고 있는지를 기록한 뒤, 

모든 bfs를 마친 후 두 인접한 방을 합한 넓이의 최대값을 구한다.


3. 계획 검증
 1. 알고리즘 측면​

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/


#define MAX 50
#define MAX_NUM_OF_ROOM 251

int M, N;

int di[4] = { 0, -1, 0, 1 };
int dj[4] = { -1, 0, 1, 0 };

int castle[MAX][MAX];
int roomNum[MAX][MAX];
bool isAdjacent[MAX_NUM_OF_ROOM][MAX_NUM_OF_ROOM];
int roomSize[MAX_NUM_OF_ROOM];

bool isInRange(int i, int j) {
	return 0 <= i && i < M && 0 <= j && j < N;
}

int bfs(int start_i, int start_j, int cur_num) {
	int roomSize = 0;

	queue<vector<int>> bfs_queue;
	bfs_queue.push({ start_i, start_j });
	roomNum[start_i][start_j] = cur_num;

	while (!bfs_queue.empty()) {
		roomSize++;
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		bfs_queue.pop();

		

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j) == false) continue;

			// 벽이 없을 경우
			if ((castle[cur_i][cur_j] & (1 << i)) == 0) {
				// 아직 방문하지 않은 방일 경우에만 방문
				if (roomNum[next_i][next_j] == 0) {
					roomNum[next_i][next_j] = cur_num;
					bfs_queue.push({ next_i, next_j });
				}
			}
			else { // 벽이 있을 경우
				// 방번호가 이미 기록된 곳이라면
				if (roomNum[next_i][next_j] != 0) {
					int next_num = roomNum[next_i][next_j];
					// 두 방이 인접한 방이라는 표시 하기
					isAdjacent[cur_num][next_num] = true;
					isAdjacent[next_num][cur_num] = true;
				}
			}
		}
	}

	return roomSize;
}


void solution() {
	// 1. 이 성에 있는 방의 개수
	// 2. 가장 넓은 방의 넓이
	int numOfRoom = 1;
	int maxRoomSize = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (roomNum[i][j] == 0) {
				roomSize[numOfRoom] = bfs(i, j, numOfRoom);
				maxRoomSize = max(maxRoomSize, roomSize[numOfRoom]);
				numOfRoom++;
			}
		}
	}

	int maxCombined = 0;
	for (int i = 1; i < numOfRoom; i++) {
		for (int j = i + 1; j < numOfRoom; j++) {
			if (isAdjacent[i][j] == true) maxCombined = max(maxCombined, roomSize[i] + roomSize[j]);
		}
	}

	cout << numOfRoom - 1 << '\n';
	cout << maxRoomSize << '\n';
	cout << maxCombined;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> castle[i][j];
		}

	solution();
}