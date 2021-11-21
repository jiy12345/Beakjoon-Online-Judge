#include<iostream>
using namespace std;

// 각 위치까지의 경로수를 저장할 배열
long long dp[100][100];

// 각 위치에서 갈 수 있는 이동거리를 입력받을 배열
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
