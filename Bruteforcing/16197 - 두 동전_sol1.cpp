#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
풀이 1. 두 동전의 상태에 따른 방문 표시를 진행하였을 경우

2256kb의 메모리만 사용하였고,
0ms 시간 내에 탐색을 끝냈다.

방문 표시를 하지 않은 풀이 2와 비교했을 때 
큐에 들어가는 노드의 수도 줄어들고 더 짧은 시간에 끝내는 것을 확인할 수 있었다.
*/

#define WALL true
#define EMPTY false

int di[4] = { 0, 0, -1, +1 };
int dj[4] = { -1, +1, 0, 0 };

int N, M;
bool isVisited[22][22][22][22];
bool Map[22][22];

bool isInRange(int i, int j) {
	return 1 <= i && i <= N && 1 <= j && j <= M;
}

int solution(vector<pair<int, int>> coinCoord) {	
	int answer = -1;

	queue<pair<int, vector<pair<int, int>>>>bfs_queue;

	bfs_queue.push(make_pair(0, coinCoord));

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front().first;
		int cur_i1 = bfs_queue.front().second[0].first;
		int cur_j1 = bfs_queue.front().second[0].second;
		int cur_i2 = bfs_queue.front().second[1].first;
		int cur_j2 = bfs_queue.front().second[1].second;
		bfs_queue.pop();

		// 11번 누른 상황이 발생하면 빠져나가기
		if (cur_depth == 11) break;

		if (isInRange(cur_i1, cur_j1) && isInRange(cur_i2, cur_j2)) {
			// 둘다 범위 내일 경우에는 그대로 bfs 진행
		}
		else if (!isInRange(cur_i1, cur_j1) && !isInRange(cur_i2, cur_j2)) {
			// 둘다 범위 밖일 때는 다음 탐색 대상으로 넘어감
			continue;
		}
		else {
			// 하나만 범위 밖일 경우 탐색 종료하고 빠져나감
			answer = cur_depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_i1 = cur_i1 + di[i];
			int next_j1 = cur_j1 + dj[i];
			int next_i2 = cur_i2 + di[i];
			int next_j2 = cur_j2 + dj[i];

			// 다음 위치가 벽이면 현 위치로 돌리기
			if (Map[next_i1][next_j1] == WALL) {
				next_i1 = cur_i1;
				next_j1 = cur_j1;
			}
			if (Map[next_i2][next_j2] == WALL) {
				next_i2 = cur_i2;
				next_j2 = cur_j2;
			}

			// 두 동전의 위치가 나오지 않을 상황일 때만 탐색 진행
			if (!isVisited[next_i1][next_j1][next_i2][next_j2]) {
				isVisited[next_i1][next_j1][next_i2][next_j2] = true;
				bfs_queue.push({ cur_depth + 1, {{next_i1, next_j1}, {next_i2, next_j2}} });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<pair<int, int>> coinCoord;

	for (int i = 0; i <= N + 1; i++) {
		if (i == 0 || i == N + 1) continue;
		string row;
		cin >> row;
		for (int j = 0; j <= M + 1; j++) {
			if (j == 0 || j == M + 1) continue;
			if (row[j - 1] != 'o') Map[i][j] = (row[j - 1] == '#');
			else {
				Map[i][j] = false;
				coinCoord.push_back(make_pair(i, j));
			}
		}
	}

	cout << solution(coinCoord);

	return 0;
}
