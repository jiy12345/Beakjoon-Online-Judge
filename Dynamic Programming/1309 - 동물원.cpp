#include<iostream>
#include<numeric>
using namespace std;

/*
1. 문제 분석
- 변수
N: 우리의 크기


- 변수 제한 사항
N: 1~100,000

- 문제 상황
사자를 가로, 세로로 붙여서 배치할 수 없다 할 때, 2 * N 크기의 우리에 사자를 배치하는 경우의 수를 9901로 나눈 나머지를 출력하라!

2. 풀이 계획


 dp[k] = dp[k-1] + 2 * (dp[k-2] + dp[k-3] + ... dp[1] + 2)
*/


int dp[100000];

int N; // 우리의 크기

int solution() {
	dp[0] = 3;
	dp[1] = 7;

	for (int i = 2;i < N;i++) {
		//dp[i] = (dp[i - 1] + 2 * (accumulate(dp, dp + i - 1, 0) + 2)) % 9901;
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}

	return dp[N - 1];
}

int main() {
	cin >> N;

	cout << solution();

}