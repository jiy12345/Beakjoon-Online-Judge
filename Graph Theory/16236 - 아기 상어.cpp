#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int space[22][22];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };

// 먹은 위치 반환
int bfs(int curSpace[][22], pair<int, int>& startLocation, int curSize) {

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>bfs_queue;

	bfs_queue.push({ 0, startLocation.first, startLocation.second, 0});

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.top()[0];
		int cur_i = bfs_queue.top()[1];
		int cur_j = bfs_queue.top()[2];
		int cur_fishSize = bfs_queue.top()[3];
		bfs_queue.pop();

		// 먹을 수 있는 물고기였을 경우
		if (cur_fishSize < curSize && cur_fishSize != 0) {
			// 다음 bfs를 위한 출발 위치 설정
			startLocation = make_pair(cur_i, cur_j);
			return cur_depth;
		}

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (curSpace[next_i][next_j] <= curSize) {
				bfs_queue.push({ cur_depth + 1, next_i, next_j, curSpace[next_i][next_j] });
				curSpace[next_i][next_j] = 100;
			}
		}
	}

	// 다 탐색했음에도 불구하고 먹을 수 있는 물고기를 찾지 못했다면 0 반환
	return 0;
}

int solution(pair<int, int> startLocation) {
	int answer = 0; // 총 시간의 합
	int curSize = 2; // 초기 크기는 2
	int numEat = 0;

	while (true) {
		int curSpace[22][22];

		copy(&space[0][0], &space[0][0] + (22 * 22), &curSpace[0][0]);

		int curTime = bfs(curSpace, startLocation, curSize);
		numEat++;
		// 먹었으므로 빈 칸으로 표시
		space[startLocation.first][startLocation.second] = 0;

		// 먹을 물고기를 찾지 못하면
		if (curTime == 0) {
			break;
		}
		
		answer += curTime;

		// 목표 횟수만큼 먹은 경우 몸집 키우기
		if (numEat == curSize) {
			numEat = 0;
			curSize++;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> startLocation;

	cin >> N;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			// 외벽 두르기
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				space[i][j] = 100;
			}
			else {
				int value;
				cin >> value;
				if (value == 9) {
					startLocation = make_pair(i, j);
					space[i][j] = 0;
				}
				else {
					space[i][j] = value;
				}
			}
		}
	}
	cout << solution(startLocation);

	return 0;
}
