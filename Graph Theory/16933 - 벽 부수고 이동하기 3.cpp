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
 벽을 최대 K개까지 부술 수 있다고 할 때, (1, 1) 위치에서 N, M위치로 이동하는 최단 거리를 출력하라

2. 풀이 계획
 각 위치별로 방문 표시를 진행하되, 방문 표시를 부순 벽의 숫자로 진행하여, 숫자가 더 작을 때만 새로 방문할 수 있도록 하면 될 듯 하다.

 같은 위치에 도착했을 때 벽을 부순 횟수가 더 많다면 갱신이 필요가 없으나,
 벽을 부순 횟수가 더 적다면 이후 경로에 영향을 끼칠 수 있으므로 고려대상에 넣어야한다.
 각 위치까지의 벽을 부순 횟수를 기록하고, 조금 더 긴 경로를 돌아왔더라도 부순 벽의 개수가 적다면 고려대상에 넣는 것으로 하면 될 듯 하다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

enum TIME { NIGHT, AFTERNOON };

int di[5] = { +1, -1, 0, 0, 0 };
int dj[5] = { 0, 0, +1, -1, 0 };

int N, M, K;
string map[1000];

inline bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

int solution() {
	int answer = -1;

	// 현 위치까지 남은 기회 기록
	// -1일 경우 아직 방문하지 않은 경우
	vector<vector<int>> chanceLeftAfternoon(N, vector<int>(M, -1));
	vector<vector<int>> chanceLeftNight(N, vector<int>(M, -1));

	queue<vector<int>> bfs_queue;

	// 처음부터 i좌표 / j좌표 / 깊이(경로의 길이) / 남은 벽 부술 수 있는 기회 / 낮밤 여부
	bfs_queue.push({ 0, 0, 1, K, AFTERNOON });
	chanceLeftAfternoon[0][0] = 0;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		int cur_chanceLeft = bfs_queue.front()[3];
		int cur_time = bfs_queue.front()[4];
		bfs_queue.pop();

		if (cur_i == N - 1 && cur_j == M - 1) return cur_depth;

		for (int i = 0; i < 5; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			int next_time = (cur_time == AFTERNOON) ? NIGHT : AFTERNOON;

			if (!isInRange(next_i, next_j)) continue;

			// 낮에
			if (cur_time == AFTERNOON) {
				// 가만히 있을 경우
				if (i == 4) {
					if (chanceLeftNight[next_i][next_j] < cur_chanceLeft - 1) {
						chanceLeftNight[next_i][next_j] = cur_chanceLeft - 1;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft - 1, next_time });
					}
					continue;
				}

				// 벽일 경우
				if (map[next_i][next_j] == '1') {
					// 부술 기회가 없을 경우 더 진행할 수 없음
					if (cur_chanceLeft == 0) continue;

					if (chanceLeftNight[next_i][next_j] < cur_chanceLeft - 1) {
						chanceLeftNight[next_i][next_j] = cur_chanceLeft - 1;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft - 1, next_time });
					}
				}
				else { // 길일 경우
					if (chanceLeftNight[next_i][next_j] < cur_chanceLeft) {
						chanceLeftNight[next_i][next_j] = cur_chanceLeft;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft, next_time });
					}
				}
			}
			else { // 밤일 경우
				// 가만히 있을 경우
				if (i == 4) {
					if (chanceLeftAfternoon[next_i][next_j] < cur_chanceLeft) {
						chanceLeftAfternoon[next_i][next_j] = cur_chanceLeft;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft, next_time });
					}
					continue;
				}

				if (map[next_i][next_j] == '0') { // 길일 경우만 진행 가능
					if (chanceLeftAfternoon[next_i][next_j] < cur_chanceLeft) {
						chanceLeftAfternoon[next_i][next_j] = cur_chanceLeft;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft, next_time });
					}
				}
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << solution();

	return 0;
}
