#include<iostream>
#include<algorithm>
using namespace std;

// dp[N][K] = 이항계수 (N, K) 
int dp[1001][501] = { 0, };

int solution(int n, int k) {
	// k가 음수로 가거나 k가 n보다 커지는 경우는 모두 0이므로
	// 더 이상 반복을 진행하지 않음!
	// nC0 = n-1C0 + n-1C-1 => n-1C-1은 존재하지 않으므로 0
	// nCn = n-1Cn + n-1Cn-1 => n-1Cn은 존재하지 않으므로 0
	// 위의 두 식에서 n-1C0 = n-1Cn-1 = 1이므로, 1만 리턴
	if (k == 0 || n == k) {
		return 1;
	}

	// 이미 저장된 값이 있을 경우
	if (dp[n][k] != 0) {
		return dp[n][k];
	}
	// 아직 저장된 값이 없을 경우
	else {
		// 새로 계산!
		dp[n][k] = (solution(n - 1, k - 1) + solution(n - 1, k)) % 10007;
		return dp[n][k];
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	// 조합의 성질 이용
	K = min(K, N - K);

	cout << solution(N, K);
}
