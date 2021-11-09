#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수열의 크기
A[i]: 수열 A의 i번째 수

- 변수 제한 사항
 N: 1~1,000
 A[i]: 1~1,000


- 문제 상황
 N과 수열 A가 주어질 때, 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

2. 풀이 계획
 - 전체 문제: N번째 수를 포함하는 N길이의 수열 A중 가장 긴 감소하는 부분 수열의 길이
 - 부분 문제: k(1 <= k < N)번째 수를 포함하는 k길이의 수열 A중 가장 긴 감소하는 부분 수열의 길이

3. 계획 검증


*/

// k 금액을 만들기 위한 경우의 수
int dp[1000] = { 0, };

int A[1000] = { 0, };

int N;

int solution() {
	
	for (int i = 0; i < N; i++) {
		// 현재의 수는 반드시 수열에 들어가도록 함
		dp[i] = 1;
		// 현재 수 이전의 모든 수들에 대해 고려
		for (int j = 0; j < i; j++) {
			// 현재 수가 이전 수보다 작아서 감소 수열이 성립하는 상황에만 고려
			// 감소 수열이 성립할 경우
			if (A[i] < A[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// 저장된 값 중 최대값 출력
	return *max_element(dp, dp + N);
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution();
}
