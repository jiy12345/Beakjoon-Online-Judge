#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N, M: 연구소의 가로, 세로 길이

- 변수 제한 사항
N, M: 3~8

- 문제 상황
 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다고 할 때,

얻을 수 있는 안전 영역 크기의 최대값을 구하여라

2. 풀이 계획

일단 모든 곳에 벽을 세워봐야 한다. 따라서 조합으로 각 N*M개의 위치 중 3개의 위치를 뽑아야 한다!

또한 그 위치에 세웠을 경우, 각 위치의 좌표를 구하고, 그 좌표들 모두가 빈곳이었을 경우에만 push할때 표시하는 BFS를 진행하여

바이러스가 몇군데에 펴져 있는 지를 세고, 이 때의 값을 처음에 입력받으며 셌던 0의 개수에서 빼면 될 듯 하다!

3. 계획 검증


*/
int N, M;
int laboratory[10][10];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

// 새로 감염된 공간을 표시하고 그 공간의 개수 반환
int spreadVirus(int tempLaboratory[][10], int start_i, int start_j) {
	int numOfNewlyInfectedSpace = 0;

	queue<pair<int, int>> bfs_queue;

	bfs_queue.push(make_pair(start_i, start_j));

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			if (tempLaboratory[next_i][next_j] == 0) {
				tempLaboratory[next_i][next_j] = 2;
				numOfNewlyInfectedSpace++;
				bfs_queue.push(make_pair(next_i, next_j));
			}
		}
	}
	return numOfNewlyInfectedSpace;
}

int countSafeSpace(int numOfZeros, int tempLaboratory[][10]) {
	int numOfNewlyInfectedSpace = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tempLaboratory[i][j] == 2) {
				numOfNewlyInfectedSpace += spreadVirus(tempLaboratory, i, j);
			}
		}
	}

	// 벽을 세운 3칸도 마저 빼줘야!
	return (numOfZeros - numOfNewlyInfectedSpace - 3);
}

int solution(int numOfZeros) {


	int maxSafeSpace = 0;

	for (int i = 1; i <= N * M; i++) {
		for (int j = i + 1; j <= N * M; j++) {
			for (int k = j + 1; k <= N * M; k++) {
				pair<int, int> newWall[3];

				// 첫번째 벽의 i, j값
				newWall[0].first = (i - 1) / M + 1;
				newWall[0].second = (i - 1) % M + 1;
				// 두번째 벽의 i, j값
				newWall[1].first = (j - 1) / M + 1;
				newWall[1].second = (j - 1) % M + 1;
				// 세번째 벽의 i, j값
				newWall[2].first = (k - 1) / M + 1;
				newWall[2].second = (k - 1) % M + 1;

				// 벽을 세워야 할 곳이 모두 빈칸일 때만 탐색 진행
				if (laboratory[newWall[0].first][newWall[0].second] == 0 &&
					laboratory[newWall[1].first][newWall[1].second] == 0 &&
					laboratory[newWall[2].first][newWall[2].second] == 0) {
					
					int tempLaboratory[10][10];

					// 임시 공간에 복사
					copy(&laboratory[0][0], &laboratory[0][0] + 10 * 10, &tempLaboratory[0][0]);
					
					// 임시 공간에 새로운 벽 세우기
					for (int l = 0; l < 3; l++) {
						tempLaboratory[newWall[l].first][newWall[l].second] = 1;
					}

					maxSafeSpace = max(maxSafeSpace, countSafeSpace(numOfZeros, tempLaboratory));
				}
			}
		}
	}

	return maxSafeSpace;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int numOfZeros = 0;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			// 외부는 벽으로 둘러싸기
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				laboratory[i][j] = 1;
			}
			else {
				cin >> laboratory[i][j];
				// 0의 개수 세기
				if (laboratory[i][j] == 0) numOfZeros++;
			}
		}
	}

	cout << solution(numOfZeros);
}