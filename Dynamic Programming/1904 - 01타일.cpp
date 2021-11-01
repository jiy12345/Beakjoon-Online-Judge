#include<iostream>
using namespace std;

// 각 항까지의 경우의 수를 저장할 배열
int dp[1000000] = { 0, };

int n;

int solution() {
	dp[0] = 1; // 1
	dp[1] = 2; // 00, 11

	for (int i = 2; i < n; i++) {
		// 모듈러 연산의 성질 이용
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	// 모듈러 연산의 성질 이용
	return dp[n - 1] % 15746;
}


int main() {
	cin >> n;

	cout << solution();
}
