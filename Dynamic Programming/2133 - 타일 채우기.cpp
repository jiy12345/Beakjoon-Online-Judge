#include<iostream>
using namespace std;

int dp[31] = { 0, };

int N = 0;

int solution() {
	// 초기값
	dp[0] = 1; // 0번 위치는 딱 맞는 경우의 수라는 것을 표현하기 위해 1로 설정!
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;

	for (int i = 4;i <= N;i++) {
		// 2칸일 때의 3가지 경우의 수 고려해주기!
		dp[i] = 3 * dp[i - 2];
		// 짝수별로 생기는 특수한 모양을 고려해주기!
		for (int j = 4;j <= i;j += 2) {
			dp[i] += 2 * dp[i - j];
		}
	}

	return dp[N];
}

int main() {
	// 초기값 입력
	cin >> N;

	cout << solution();
}
