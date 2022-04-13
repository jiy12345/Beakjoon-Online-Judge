#include<iostream>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
N: 육각 보드의 가로, 세로 길이



- 변수 제한 사항
N: 1 ~ 50

- 문제 상황
 육각 보드의 일부 칸을 색을 칠하려고 한다.
 두 칸이 변을 공유하는 경우 같은 색으로 칠할 수 없다.

 어떤 칸을 색칠해야 하는지 주어졌을 때, 필요한 색의 최소 종류를 구하라

2. 풀이 계획

 나올 수 있는 경우는 다음과 같다.

 0: 칠해야 할 곳이 없을 때
 1: 칠해야 할 곳들이 모두 따로 떨어져 있을 때
 2: 칠해야 할 곳들이 모여 있는 경우가 있으나 덩어리로 뭉쳐 있는 경우가 없을 때
 3: 칠해야 할 곳들이 모여 있는 경우가 있고 덩어리로 뭉쳐 있는 경우도 있을 때

 1까지는 모든 위치를 탐색하며 색칠한 곳이 있는 것을 찾아내면 된다.

 문제는 2와 3이다.

 bfs를 진행하되, 한 지점으로부터 인접한 색칠해야할 지점에 대하여 서로 인접한지를 체크하여 2번과 3번을 구분하면 될 듯 하다.

 인접하다는 것을 어떻게 체크해야 할까?

 어떤 노드까지 인접 체크를 해야할까?(방문표시는?)

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


int N;
char hexaBoard[50][50];
int color[50][50];
int answer = 0;

int di[6] = { -1, -1, 0, +1, +1, 0};
int dj[6] = { 0, +1, +1, 0, -1, -1};

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void getColorNum(int cur_i, int cur_j, int cur_color) {
	color[cur_i][cur_j] = cur_color;

	answer = max(answer, 1);

	for (int i = 0; i < 6; i++) {
		int next_i = cur_i + di[i];
		int next_j = cur_j + dj[i];

		if (!isInRange(next_i, next_j)) continue;

		if (hexaBoard[next_i][next_j] == 'X') {
			if (color[next_i][next_j] == -1) {
				getColorNum(next_i, next_j, 1 - cur_color);
			}
			answer = max(answer, 2);

			if (color[next_i][next_j] == cur_color) {
				answer = max(answer, 3);
			}
		}
	}

}

int solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (hexaBoard[i][j] == 'X' && color[i][j] == -1) {
				getColorNum(i, j, 0);
			}
			if (answer == 3) break;
		}
		if (answer == 3) break;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> hexaBoard[i][j];
		}
	}

	memset(color, -1, sizeof(color));
	
	cout << solution();

	return 0;
}