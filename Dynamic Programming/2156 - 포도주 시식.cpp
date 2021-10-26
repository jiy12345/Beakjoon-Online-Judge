#include<iostream>
using namespace std;

// 각 잔의 와인 양을 저장할 배열
int amount_of_wine[10000] = { 0, };
// 각 항까지의 최대값을 저장할 배열
int dp[10000] = { 0, };

int n;

int solution() {
	// 첫 잔까지의 최대값: 첫잔의 양 그대로
	dp[0] = amount_of_wine[0];
	// 두번째 잔까지의 최대값: 첫째 잔의 양 + 두번째 잔의 양
	dp[1] = amount_of_wine[0] + amount_of_wine[1];
	// 세번째 잔까지의 최대값: (첫잔 + 두번째 잔), (첫잔 + 세번째 잔), (두번째 잔 + 세번째 잔)중 가장 큰 값!
	dp[2] = max(dp[1], amount_of_wine[2] + max(amount_of_wine[0], amount_of_wine[1]));

	for (int i = 3; i < n; i++) {
		// 점화식: (이전항까지의 최대값), (전전항까지의 최대값 + 현재항 값), (전전전항까지의 최대값 + 이전항 + 현재항)중 가장 큰 값
		dp[i] = max(dp[i - 1], amount_of_wine[i] + max(dp[i - 2], amount_of_wine[i - 1] + dp[i - 3]));
	}
	
	return dp[n - 1];
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> amount_of_wine[i];
	}

	cout << solution();
}
