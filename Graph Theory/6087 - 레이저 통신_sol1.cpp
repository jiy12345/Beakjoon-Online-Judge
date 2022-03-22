#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
W, H: 지도의 세로, 가로 길이

- 변수 제한 사항
W, H: 1 ~ 100

.: 빈 칸
*: 벽
C: 레이저로 연결해야 하는 칸

C는 항상 두개이며, 레이저로 연결할 수 있는 입력만 주어진다!

- 문제 상황
 
 두 개의 c 위치를 연결하기 위해 사용되어야 하는 거울(90도 회전)의 개수의 최소값을 구하여라

2. 풀이 계획

 일반적인 bfs와 다르게, 90도 회전의 개수를 체크한다!

 180도 회전은 어차피 방문 표시로 인해 이루어지지 않을 것이므로, 모든 회전의 개수(방향이 바뀐 횟수)를 세면 될 듯 하다.



3. 계획 검증

bfs는 그런데 거리상 가까운 노드가 먼저 나온다.

거리가 가까운 것이 회전수가 적다는 것을 보장하는가?
그렇지 않다. 따라서 priority_queue를 사용하여 회전 수에 따라서 정렬되도록 해야할 듯 하다.


*/

enum DIRECTION{ SOUTH, NORTH, EAST, WEST, NUM_OF_DIRECTION };
#define MAX 101

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

		//cout << "cur_i: " << cur_i << ", cur_j: " << cur_j << ", cur_numOfMirror: " << cur_numOfMirror << endl;

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
