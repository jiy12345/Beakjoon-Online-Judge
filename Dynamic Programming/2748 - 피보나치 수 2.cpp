#include<iostream>
using namespace std;

// 각 항까지의 최대값을 저장할 배열
long long dp[90] = { 0, };

int n;

long long solution() {
	// 1항부터 쓰기
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < n; i++) {
		// 점화식: Fn = Fn-1 + Fn-2 (n ≥ 2)
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n - 1];
}

int main() {
	cin >> n;

	cout << solution();
}
