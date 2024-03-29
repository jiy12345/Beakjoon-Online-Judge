#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 102

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int h, w;
char prison[MAX][MAX];
int numOfDoors[MAX][MAX][3];

inline bool isInRange(int i, int j) {
	return (0 <= i && i <= h + 1 && 0 <= j && j <= w + 1);
}

void bfs(int start_i, int start_j, int personNum) {
	numOfDoors[start_i][start_j][personNum] = 0;

	deque<pair<int, int>>bfs_queue;

	bfs_queue.push_back({ start_i, start_j });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop_front();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			// 아예 지나갈 수 없는 경우
			if (isInRange(next_i, next_j) == false || prison[next_i][next_j] == '*') continue;

			// 문일 경우에는 나중에 처리해주도록 뒤에 푸시
			if (prison[next_i][next_j] == '#') {
				if (numOfDoors[cur_i][cur_j][personNum] + 1 < numOfDoors[next_i][next_j][personNum]) {
					numOfDoors[next_i][next_j][personNum] = numOfDoors[cur_i][cur_j][personNum] + 1;
					bfs_queue.push_back({ next_i, next_j });
				}
			}
			else { // 빈 공간의 경우 먼저 처리하도록 함
				// 다만 문을 더 적게 열었을 경우에만 새로 방문하도록 함
				if (numOfDoors[cur_i][cur_j][personNum] < numOfDoors[next_i][next_j][personNum]) {
					numOfDoors[next_i][next_j][personNum] = numOfDoors[cur_i][cur_j][personNum];
					bfs_queue.push_front({ next_i, next_j });
				}
			}
		}
	}
}

int solution(vector<pair<int, int>>locationsOfPeople) {
	memset(numOfDoors, 100 * 100, sizeof(numOfDoors));
	int answer = 100 * 100;

	for (int i = 0; i < 3; i++) {
		bfs(locationsOfPeople[i].first, locationsOfPeople[i].second, i);
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int totalNumOfDoors = numOfDoors[i][j][0] + numOfDoors[i][j][1] + numOfDoors[i][j][2];
			if (prison[i][j] == '#') totalNumOfDoors -= 2;

			answer = min(answer, totalNumOfDoors);
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> h >> w;

		vector<pair<int, int>> locationsOfPeople;
		locationsOfPeople.push_back({ 0, 0 }); // 상근이의 위치

		for (int j = 0; j <= h + 1; j++) {
			for (int k = 0; k <= w + 1; k++) {
				if (j == 0 || j == h + 1 || k == 0 || k == w + 1) prison[j][k] = '.';
				else {
					cin >> prison[j][k];
					if (prison[j][k] == '$') locationsOfPeople.push_back({ j, k });
				}
			}
		}

		cout << solution(locationsOfPeople) << '\n';
	}

	return 0;
}
