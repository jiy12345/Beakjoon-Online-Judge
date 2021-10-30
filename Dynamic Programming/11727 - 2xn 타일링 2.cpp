#include<iostream>
using namespace std;

// 각 항까지의 최대값을 저장할 배열
int dp[1000] = { 0, };

int n;

int solution() {
	dp[0] = 1; // (2×1)
	dp[1] = 3; // (2×1 2개), (1×2 2개), (2×2 1개)

	for (int i = 2; i < n; i++) {
		// 점화식 
		// 모듈러 연산의 성질 이용
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	return dp[n - 1] % 10007;
}


int main() {
	cin >> n;

	cout << solution();
}
