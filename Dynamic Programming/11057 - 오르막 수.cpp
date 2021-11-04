#include<iostream>
#include<numeric>
using namespace std;

// dp[i][j]: j로 끝나는 i길이 오르막 수의 경우의 수
int dp[1000][10] = { {0, } };

int N;

int solution() {
	// 각각의 첫 위치는 하나의 경우의 수만 가짐
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			// dp[i][j] = dp[i-1][0] + dp[i-1][1] + ... + dp[i-1][j] 
			// 모듈러 연산의 성질 활용
			dp[i][j] = accumulate(dp[i - 1], dp[i - 1] + j + 1, 0) % 10007;
		}
	}

	// 모듈러 연산의 성질 활용
	return accumulate(dp[N - 1], dp[N - 1] + 10, 0) % 10007;
}

int main() {

	cin >> N;

	cout << solution();
	
	return 0;
}
