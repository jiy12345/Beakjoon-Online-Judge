#include<iostream>
#include<queue>
using namespace std;

enum DIRECTION { SOUTH, NORTH, EAST, WEST, NUM_OF_DIRECTION };
#define MAX 101

/*
- queue를 사용한 풀이

사용한 메모리: 2428KB	
걸린 시간: 12ms
	
priority 큐는 내부를 정렬된 상태로 유지하는데 시간이 조금 더 들어가므로, 큐를 사용하면 개선되지 않을까 해서 시도해보았다.

그런데 큐를 이용하면, 처음 도착지를 만났을 때 거울의 사용 횟수가 최소값이라는 것을 보장하지 못하므로,
처음 도착지를 만났을 때 반복을 종료하는 것이 아니라 더 이상 탐색할 위치가 없을 때까지 탐색해야 한다!

그래서 그런지 오히려 시간은 priority_queue를 사용하였을 때보다 오래 걸리는 것으로 확인되었다.
*/

int di[9] = { +1, -1, 0, 0 };
int dj[9] = { 0, 0, +1, -1 };

string Map[MAX];

int W, H;

inline bool isInRange(int i, int j) {
	return 0 <= i && i < H && 0 <= j && j < W;
}

int solution(vector<pair<int, int>> C_Coords) {
	int answer = MAX * MAX;

	vector<vector<vector<int>>>usedNumOfMirror(NUM_OF_DIRECTION, vector<vector<int>>(H, vector<int>(W, MAX * MAX)));
	queue<vector<int>> bfs_queue;

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
			bfs_queue.push({ 0, direction, next_i, next_j });
		}
	}

	while (!bfs_queue.empty()) {
		int cur_numOfMirror = bfs_queue.front()[0];
		int prev_direction = bfs_queue.front()[1];
		int cur_i = bfs_queue.front()[2];
		int cur_j = bfs_queue.front()[3];
		bfs_queue.pop();

		if (cur_i == end_i && cur_j == end_j) {
			answer = min(answer, cur_numOfMirror);
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
