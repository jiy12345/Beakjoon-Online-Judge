#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N, M: 행렬의 세로, 가로 길이
K: 벽을 부술 수 있는 횟수

 - 변수 제한 사항
N, M: 1 ~ 1,000
K: 1 ~ 10

(1, 1)과 (N, M)은 항상 빈 공간이다!

- 문제 상황
빈칸과 벽으로 이루어진 8 x 8 체스판에서 캐릭터는 가장 왼쪽 아래 칸에 있으며, 가장 오른쪽 위 칸으로 이동해야 한다고 할 때,
캐릭터가 오른쪽 위 칸으로 이동할 수 있는지 여부를 구하라.

- 벽은 다음과 같은 규칙에 의해 움직인다.
 1) 1초마다 모든 벽이 아래에 있는 행으로 한칸씩 내려간다.
 2) 가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다.

- 캐릭터는 다음과 같은 규칙에 의해 움직인다.
 1) 캐릭터는 인접한 한 칸 또는 대각선 방향으로 이동하거나, 현재 위치에 서 있을 수 있다.
 2) 이동할 때는 빈 칸으로만 이동할 수 있다.

- 1초 동안 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다.
- 벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터는 이동할 수 없다.

2. 풀이 계획
 원래는 최단 경로를 구하는 문제가 아니므로 depth는 필요 없지만, 서로 다른 타이밍에 도착한다면 결과가 달라질 수 있으므로 체크해야 할 듯하다.

 서로다른 시점에 같은 노드를 방문하는 경우도 다른 경우로 봐야할 듯 하다.

 따라서 

 1. 맵을 입력받는다.

 2. bfs를 진행한다.
  - 필요한 정보: i, j, depth
  - 방문 표시: i, j, depth

   => 이 때의 depth는 30을 넘지 않을 것으로 보이므로(8번이면 맵에서 모든 벽이 사라지는데, 이 때의 거리는 길어봐야 14 이므로)

   => 이 때, 벽의 움직임은 어떻게 표현해야 할까?
   => 타이밍이 8번밖에 되지 않으므로, 굳이 



3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define BLANK false
#define WALL  true
#define MAX   8

int di[9] = { +1, -1, 0, 0, +1, -1, +1, -1, 0 };
int dj[9] = { 0, 0, +1, -1, +1, +1, -1, -1, 0 };

string Map[8];

// 각 시점별 맵
bool mapOverTime[MAX][MAX][9];
bool isVisited[MAX][MAX][30];

void calCulateMapOverTime() {
	// 마지막 8 시점은 어차피 모든 벽이 사라져 빈칸이므로
	// 마지막을 제외한 모든 시점에 대해 반복
	for (int i = 0; i < MAX; i++) {
		// 각 시점별로 시작 행이 달라짐
		for (int j = i; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				if (Map[j - i][k] == '#') mapOverTime[j][k][i] = true;
			}
		}
	}
}

inline bool isInRange(int i, int j) {
	return 0 <= i && i < MAX && 0 <= j && j < MAX;
}

int solution() {
	int answer = 0;

	queue<vector<int>> bfs_queue;

	// 처음부터 i좌표 / j좌표 / 깊이(해당 노드를 방문한 타이밍)
	bfs_queue.push({ MAX - 1, 0, 0, });
	isVisited[MAX - 1][0][0] = true;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_time = bfs_queue.front()[2];
		bfs_queue.pop();
		
		cout << "cur_i: " << cur_i << ", cur_j: " << cur_j << ", cur_time: " << cur_time << endl;

		if (cur_i == 0 && cur_j == MAX - 1) {
			answer = 1;
			break;
		}

		// 8 이후 시간대에는 모든 벽이 사라지므로, 의미가 없음
		if (cur_time > 8) cur_time = 8;

		for (int i = 0; i < 9; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			int next_time = cur_time + 1;

			// 범위를 벗어나는 위치면 탐색 진행하지 않음
			if (!isInRange(next_i, next_j)) continue;

			// 8 이후 시간대에는 모든 벽이 사라지므로, 의미가 없음
			if (next_time > 8) next_time = 8;

			if (mapOverTime[next_i][next_j][cur_time] == BLANK && // 현재 시간에 벽이 아니며,
				mapOverTime[next_i][next_j][next_time] == BLANK && // 다음 시간에도 벽이 아니며,
				isVisited[next_i][next_j][next_time] == false) { // 다음 시간에 방문하지 않은 노드일 경우에만 탐색
				isVisited[next_i][next_j][next_time] = true;
				bfs_queue.push({ next_i, next_j, next_time });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> Map[i];

	calCulateMapOverTime();

	for (int i = 0; i < MAX; i++) {
		// 각 시점별로 시작 행이 달라짐
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				cout << mapOverTime[j][k][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << solution();

	return 0;
}
