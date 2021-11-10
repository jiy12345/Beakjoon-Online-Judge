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
이항 계수는 조합과 같으므로, NCK를 구해야하는 문제이며, 조합은 다음과 같은 공식에 따라 분할정복이 가능하다.

nCk = n-1Ck-1 + n-1Ck

따라서 2차원배열로 구성하여, Top-down 방식으로 재귀로 구현하고, 이미 구해진 값은 다시 구하지 않도록 하여 반복을 줄여야 할 듯 하다!

Top-down 방식으로 하는 이유는 문제를 보면 위에 구해야 하는 값은 하나로 모이지만, 아래로 갈 수록 구해야 하는 값이

그리고 조합의 공식에는 다음과 같은 것이 있다!

nCk = nCn-k

k 부분이 작으면 계산이 용이하므로, k와 n-k중 작은 수를 선택하려 한다!

 - 전체 문제: N번째 수를 포함하는 N길이의 수열 A중 가장 긴 감소하는 부분 수열의 길이
 - 부분 문제: k(1 <= k < N)번째 수를 포함하는 k길이의 수열 A중 가장 긴 감소하는 부분 수열의 길이

3. 계획 검증


*/

// dp[N][K] = 이항계수 (N, K) 
int dp[1001][501] = { 0, };



int solution(int N, int K) {
	if (K > N) {
		return 0;
	}
	if (K == 1) {
		return N;
	}
	else if (K == 0) {
		return 1;
	}

	if (dp[N][K] != 0) {
		return dp[N][K] % 10007;
	}
	else {
		dp[N][K] = solution(N - 1, K - 1) + solution(N - 1, K);
		return dp[N][K] % 10007;
	}
}


int main() {
	int N, K;
	cin >> N >> K;

	K = min(K, N - K);

	cout << solution(N, K);
}
