#include<iostream>
#include<queue>
using namespace std;

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

	cout << solution();

	return 0;
}
