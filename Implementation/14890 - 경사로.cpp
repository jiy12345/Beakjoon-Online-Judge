#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
1. 문제 분석
- 변수
N: 열, 행의 길이
L: 경사로의 길이

- 변수 제한 사항
N: 2 ~ 100
L: 1 ~ N

- 문제 상황
 지나갈 수 있는 길은 다음과 같은 조건을 만족시켜야 한다.

 - 길에 속한 모든 칸의 높이가 같다.
 - 모든 칸의 높이가 같지 않다면 경사로로 이어져 있어야 한다.

 경사로가 다음과 같은 조건을 가지고 설치되며 개수의 제한이 없다고 할 때, 
 
 - 경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
 - 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
 - 경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.

 지나갈 수 있는 길의 개수를 구하여라.

2. 풀이 계획

높은 쪽에서 낮은 쪽으로 진행하며, 조건을 만족시키지 못했을 때 빠져나가고(지나갈 수 없는 길) 모든 조건을 통과했을 경우 지나갈 수 있는 길로 하는 것으로 하자.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N, L;
int Map[100][100];

bool isPassableRow(int j) {
	bool isPassable = true;

	return isPassable;
}

bool isPassableColumn(int j) {
	bool isPassable = true;


	return isPassable;
}

bool isPassable(int i, int j) {
	if (i == 0) {
		return isPassableColumn(j);
	}
	else if (j == 0) {
		return isPassableRow(i);
	}
}
void solution(string command) {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer += isPassable(i, 0) ? 1 : 0;
		answer += isPassable(0, i) ? 1 : 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	return 0;
}