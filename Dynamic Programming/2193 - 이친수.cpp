#include<iostream>
using namespace std;

// dp[n]: n 자리 수 이친수의 개수
long long dp[90] = { 0, };

// 구할 이친수의 자리수
int N;

long long solution() {
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < N; i++) {
		// 점화식: Fn = Fn-1 + Fn-2 (n ≥ 2)
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[N - 1];
}


int main() {
	cin >> N;

	cout << solution();
}
