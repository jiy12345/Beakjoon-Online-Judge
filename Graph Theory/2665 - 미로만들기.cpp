#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
1. 문제 분석
- 변수
n: 미로의 가로, 세로 길이



- 변수 제한 사항
n: 1 ~ 1,000
m: 1 ~ 100,000

버스 비용: 100,000
항상 시작점에서 도착점으로 가는 경로가 존재한다.

- 문제 상황
 그래프의 상황, 시작점과 도착점이 주어졌을 때,

 최소비용을 갖는 경로에 포함되어 있는 도시의 개수, 경로를 출력한다.




2. 풀이 계획

1, v1, v2 지점에서의 다익스트라를 진행한 후,

경로가 있을 경우에만
1 -> v1
v1 -> v2
v2 -> N
거리의 합을 더한 값을 출력하면 될 듯 하다.

3. 계획 검증
*/

#define MAX 50

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int n;
string maze[MAX];

inline bool isInRange(int i, int j) {
	return (0 <= i && i < n && 0 <= j && j < n);
}

int solution() {
	vector<vector<int>> numOfWalls(n, vector<int>(MAX * MAX, MAX * MAX));

	numOfWalls[0][0] = 0;

	deque<pair<int, int>>bfs_queue;

	bfs_queue.push_back({ 0, 0 });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop_front();

		if (cur_i == n - 1 && cur_j == n - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j)) {
				if (maze[next_i][next_j] == '0') {
					if (numOfWalls[cur_i][cur_j] + 1 < numOfWalls[next_i][next_j]) {
						numOfWalls[next_i][next_j] = numOfWalls[cur_i][cur_j] + 1;
						bfs_queue.push_back({ next_i, next_j });
					}
				}
				else {
					if (numOfWalls[cur_i][cur_j] < numOfWalls[next_i][next_j]) {
						numOfWalls[next_i][next_j] = numOfWalls[cur_i][cur_j];
						bfs_queue.push_front({ next_i, next_j });
					}
				}
			}
		}
	}

	return numOfWalls[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	cout << solution();

	return 0;
}
