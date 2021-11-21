#include<iostream>
#include<numeric>
using namespace std;

/*
1. 문제 분석
- 변수
N: 게임판의 가로, 세로 길이

- 변수 제한 사항
N: 4~100
칸에 적혀있는 수: 0~9

경로의 개수는 2^63 - 1보다 작거나 같다! => long long으로 해야!

- 문제 상황
각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미하며, 반드시 오른쪽이나 아래쪽으로만 이동해야 한다!
한번 점프를 할 때 방향을 바꾸면 안되며, 즉 한 칸에서 오른쪽만 이동하거나 아래쪽으로만 이동해야 한다!

0은 더 이상 진행을 막는 종착점이다.

각 위치의 갈 수 있는 거리가 주어질 때, 
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하여라

2. 풀이 계획

각 위치별로 하나씩 더해가면 될 듯 하다!

*/


long long dp[100][100];

int map[100][100];

int N;

long long solution() {
	// 첫 위치는 무조건 갈 수 있으므로 표시!
	dp[0][0] = 1;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			// 현 위치가 0일 경우 계산 x
			if (map[i][j] == 0) {
				continue;
			}
			// 아래로 이동
			if (i + map[i][j] < N) {
				dp[i + map[i][j]][j] += dp[i][j];
			}
			// 오른쪽 이동
			if (j + map[i][j] < N) {
				dp[i][j + map[i][j]] += dp[i][j];
			}
		}

	}
	return dp[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}
	
	cout << solution();
}