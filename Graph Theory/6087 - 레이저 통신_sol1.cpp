#include<iostream>
#include<queue>
using namespace std;

enum DIRECTION{ SOUTH, NORTH, EAST, WEST, NUM_OF_DIRECTION };
#define MAX 101

int di[9] = { +1, -1, 0, 0 };
int dj[9] = { 0, 0, +1, -1 };

/*
- priority_queue를 사용한 풀이
사용한 메모리: 2648KB	
걸린 시간: 4ms
	
priority 큐를 사용하면 먼저 등장하는 경로가 항상 거울을 적게 사용한 경로임을 보장할 수 있으므로, 시간 단축이 되지 않을까 하여 사용하였다.

큐를 사용하였을 때와 다르게 priority 큐를 사용하였을 때는 처음 도착지를 만났을 때가 항상 거울을 가장 적게 사용한 경로로 진행하였을 때이므로,
해당 시점에서 바로 종료가 가능하다.

시간을 확인한 결과 큐를 사용하였을 때보다 빠르게 완료한 것을 확인할 수 있었다.
*/

string Map[MAX];

int W, H;

inline bool isInRange(int i, int j) {
	return 0 <= i && i < H && 0 <= j && j < W;
}

int solution(vector<pair<int, int>> C_Coords) {
	int answer = MAX * MAX;

	vector<vector<vector<int>>>usedNumOfMirror(NUM_OF_DIRECTION, vector<vector<int>>(H, vector<int>(W, MAX * MAX)));
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> bfs_queue;

	int start_i = C_Coords[0].first;
	int start_j = C_Coords[0].second;
	for (int direction = 0; direction < NUM_OF_DIRECTION; direction++) {
		usedNumOfMirror[direction][start_i][start_j] = 0;
	}
	
	int end_i = C_Coords[1].first;
	int end_j = C_Coords[1].second;

	// 4방향의 초기 이동 상황 모두 푸시
	for (int direction = 0; direction < NUM_OF_DIRECTION; direction++) {
		int next_i = start_i + di[direction];
		int next_j = start_j + dj[direction];

		if (!isInRange(next_i, next_j)) continue;

		if (Map[next_i][next_j] != '*') {
			usedNumOfMirror[direction][next_i][next_j] = 0;
			// 사용한 거울의 개수 / 이전 방향 / i좌표 / j좌표 
			bfs_queue.push({ 0, direction, next_i, next_j  });
		}
	}

	while (!bfs_queue.empty()) {
		int cur_numOfMirror = bfs_queue.top()[0];
		int prev_direction = bfs_queue.top()[1];
		int cur_i = bfs_queue.top()[2];
		int cur_j = bfs_queue.top()[3];
		bfs_queue.pop();

		if (cur_i == end_i && cur_j == end_j) {
			answer = cur_numOfMirror;
			break;
		}

		for (int cur_direction = 0; cur_direction < NUM_OF_DIRECTION; cur_direction++) {
			int next_numOfMirror = cur_numOfMirror;
			int next_i = cur_i + di[cur_direction];
			int next_j = cur_j + dj[cur_direction];

			if (!isInRange(next_i, next_j)) continue;

			// 방향 전환이 있을 경우
			if (prev_direction != cur_direction) next_numOfMirror++;

			if (Map[next_i][next_j] != '*' && usedNumOfMirror[cur_direction][next_i][next_j] > next_numOfMirror) {
				usedNumOfMirror[cur_direction][next_i][next_j] = next_numOfMirror;

				// 사용한 거울의 개수 / i좌표 / j좌표 / 이전 방향
				bfs_queue.push({ next_numOfMirror, cur_direction, next_i, next_j });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> C_Coords;

	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		cin >> Map[i];
		for (int j = 0; j < W; j++) if (Map[i][j] == 'C') C_Coords.push_back({ i, j });
	}

	cout << solution(C_Coords);

	return 0;
}
