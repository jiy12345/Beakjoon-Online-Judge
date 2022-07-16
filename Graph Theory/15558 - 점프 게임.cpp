#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 각 줄의 길이
 k: 점프 시 이동해야 하는 칸

- 변수 제한 사항
 N, k:  1 ~ 100,000
 0: 갈 수 없는 칸
 1: 갈 수 있는 칸

- 문제 상황
매 초마다 다음과 같이 이동한다고 할 때
한 칸 앞으로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i+1번 칸으로 이동한다.
한 칸 뒤로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i-1번 칸으로 이동한다.
반대편 줄로 점프한다. 이때, 원래 있던 칸보다 k칸 앞의 칸으로 이동해야 한다. 예를 들어, 현재 있는 칸이 왼쪽 줄의 i번 칸이면, 오른쪽 줄의 i+k번 칸으로 이동해야 한다.

2. 풀이 계획


1. bfs를 방문표시를 하며 진행한다.
 => 이 때 깊이 값에 cur_depth에 따라 cur_depth - 1까지의 칸은 접근할 수 없도록 한다.
2. 1번에서 표시한 칸을 만난다면 1을 반환하고, 그렇지 않고 끝까지 탐색했음에도 발견하지 못한다면 0을 반환한다.


3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define LEFT 0
#define RIGHT 1

int di[3]			= { 1, -1, 0 };
int dLeftOrRight[3]	= { 0, 0, 1 };

int N, k;
string gameMap[2];

bool bfs() {
	
	queue<vector<int>>bfs_queue;

	bfs_queue.push({ 0, 0, LEFT });
	while (!bfs_queue.empty()) {
		int cur_depth		= bfs_queue.front()[0];
		int cur_i			= bfs_queue.front()[1];
		int cur_leftOrRight = bfs_queue.front()[2];
		bfs_queue.pop();

		for (int i = 0; i < 3; i++) {
			int next_depth			= cur_depth + 1;
			int next_i				= cur_i + di[i];
			int next_leftOrRight	= (cur_leftOrRight + dLeftOrRight[i]) % 2;
			
			// 승리 조건
			if (next_i >= N) return true;
			
			if (next_i < 0 || next_i <= cur_depth || gameMap[next_leftOrRight][next_i] == '0') continue;
			gameMap[next_leftOrRight][next_i] = '0'; // 방문 표시
			bfs_queue.push({ next_depth, next_i, next_leftOrRight });

		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;
	di[2] = k;

	for (int i = 0; i < 2; i++)
		cin >> gameMap[i];

	cout << bfs();
}