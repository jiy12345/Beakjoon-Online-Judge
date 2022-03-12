#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 게임판의 세로 길이
M: 게임판의 가로 길이

- 변수 제한 사항
N, M: 2 ~ 50


- 문제 상황
점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.

 - 모든 k개의 점은 서로 다르다.
 - k는 4보다 크거나 같다.
 - 모든 점의 색은 같다.
 - 모든 1 ≤ i ≤ k-1에 대해서, di와 di+1은 인접하다. 또, dk와 d1도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.

게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 여부를 판단하라.

 2. 풀이 계획
 벽을 최소 몇개 부수어야 하는지에 대한 문제이므로, 벽이 부서질 때만 비용이 발생한다고 보면 된다.

 따라서 0 - 1 BFS라고 볼 수 있다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int N, M;
string gameBoard[50];
bool isVisited[50][50];
int dist[50][50];

inline bool isInRange(int i, int j) {
	return (0 <= i && i < N && 0 <= j && j < M);
}

bool isCycle(char Color, int cur_i, int cur_j, int cur_depth) {
	if (isVisited[cur_i][cur_j]) {
		if (cur_depth - dist[cur_i][cur_j] >= 4) // 이동 횟수에서 현재 위치에 저장된 시작점과의 거리 차가 4 이상 = 싸이클
			return true;
		else
			return false;
	}

	isVisited[cur_i][cur_j] = true;
	dist[cur_i][cur_j] = cur_depth;

	for (int k = 0; k < 4; k++) {
		int next_i = cur_i + di[k];
		int next_j = cur_j + dj[k];

		if (isInRange(next_i, next_j) && gameBoard[next_i][next_j] == Color)
			if (isCycle(Color, next_i, next_j, cur_depth + 1))
				return true;
	}

	return false;
}

string solution() {
	// 모든 지점에 대해
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (isVisited[i][j] == false) // 아직 탐색하지 않은 곳일 경우
				if (isCycle(gameBoard[i][j], i, j, 0))
					return "Yes";

	return "No";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		cin >> gameBoard[i];

	cout << solution();
	
	return 0;
}