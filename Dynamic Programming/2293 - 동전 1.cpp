#include<iostream>
using namespace std;

// k 금액을 만들기 위한 경우의 수
int dp[10001] = { 0, };

int coin[100] = { 0, };

int n, k;

// 조합으로 구하기
// 사용한 동전의 구성이 같은데, 순서만 다른 경우는 같은 경우로 볼 경우
int solution() {

	// 정확히 각 코인의 가치를 가진 금액을 만들 때를 위한 초기값
	dp[0] = 1;

	// 모든 코인에 대해 반복
	for (int i = 0; i < n; i++) {
		// 모든 금액에 대해 반복
		// 현재 코인 금액 이하의 금액은 만들 수 없으므로,
		// 현재 코인의 금액부터 시작
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	return dp[k];
}

// 순열로 구하기
// 사용한 동전의 구성이 같은데, 순서만 다른 것도 다른 경우로 볼 경우
//int solution() {
//
//	// 정확히 각 코인의 가치를 가진 금액을 만들 때를 위한 초기값
//	dp[0] = 1;
//
//	// 모든 금액에 대해 반복
//	for (int i = 1; i <= k; i++) {
//		// 모든 코인에 대해 반복
//		for (int j = 0; j < n; j++) {
//			if (i - coin[j] >= 0) {
//				dp[i] += dp[i - coin[j]];
//			}
//		}
//	}
//
//	return dp[k];
//}

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	cout << solution();

	return 0;
}
