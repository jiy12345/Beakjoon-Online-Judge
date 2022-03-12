#include<iostream>
using namespace std;

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
