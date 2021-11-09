#include<iostream>
#include<algorithm>
using namespace std;

// dp[k]: k(1 <= k < N)번째 수를 포함하는 k길이의 수열 A중 가장 긴 감소하는 부분 수열의 길이
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
				// 현재 저장된 값과 이번에 고려하는 값 비교하여 더 큰 값 저장
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
