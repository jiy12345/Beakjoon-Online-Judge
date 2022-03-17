#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int N, M, K;
bool isVisited[1000][1000];
string map[1000];

inline bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

int solution() {
	int answer = -1;

	// 현 위치까지 남은 기회 기록
	// -1일 경우 아직 방문하지 않은 경우
	vector<vector<int>> chanceLeft(N, vector<int>(M, -1));

	queue<vector<int>> bfs_queue;

	// 처음부터 i좌표 / j좌표 / 깊이(경로의 길이) / 남은 벽 부술 수 있는 기회
	bfs_queue.push({ 0, 0, 1, K });
	chanceLeft[0][0] = 0;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		int cur_chanceLeft = bfs_queue.front()[3];
		bfs_queue.pop();

		if (cur_i == N - 1 && cur_j == M - 1) return cur_depth;

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			if (!isInRange(next_i, next_j)) continue;
			// 벽일 경우
			if (map[next_i][next_j] == '1') {
				// 부술 기회가 없을 경우 더 진행할 수 없음
				if (cur_chanceLeft == 0) continue;
				
				if (chanceLeft[next_i][next_j] < cur_chanceLeft - 1) {
					chanceLeft[next_i][next_j] = cur_chanceLeft - 1;
					bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft - 1 });
				}
			}
			else { // 길일 경우
				if (chanceLeft[next_i][next_j] < cur_chanceLeft) {
					chanceLeft[next_i][next_j] = cur_chanceLeft;
					bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft });
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
