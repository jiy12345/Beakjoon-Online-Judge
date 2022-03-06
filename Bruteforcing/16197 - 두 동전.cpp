#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*
1. 문제 분석
- 변수
N: 게임 판의 세로 길이
M: 게임 판의 가로 길이

- 변수 제한 사항
N, M: 20

- 문제 상황
보드는 벽이나 빈칸으로 이루어져 있고,

동전이 두 개의 빈칸에 놓여져 있고,

 두 동전은 "왼쪽", "오른쪽", "위", "아래"와 같이 4가지 방향으로 이동할 수 있으며, 

동전이 다음과 같이 이동한다고 할 때,

- 동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
- 동전이 이동하려는 방향에 칸이 없으면 동전은 보드 바깥으로 떨어진다.
- 그 외의 경우에는 이동하려는 방향으로 한 칸 이동한다.이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다.

 두 동전 중 하나만 보드에서 떨어뜨리기 위해 해야하는 이동의 최소 횟수를 출력한다.

 만약 두 동전을 떨어뜨릴 수 없거나, 떨어뜨리기 위해 버튼을 10번보다 많이 눌러야 한다면 -1을 출력한다.

2. 풀이 계획

일단 10,000이 입력의 최대 크기이므로, 무작정 처음부터 돌리는 것은 불가능하다.

따라서 다음 순열을 실제 구해야 하는데, 다음 순열이라는 것은 어떻게 표현할까?

=> 정렬되는 과정이라고 볼 수도 있겠다.

3. 계획 검증


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