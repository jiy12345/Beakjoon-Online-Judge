#include<iostream>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
N: 카드 팩 종류의 수/ 민규가 구매하려는 카드의 수/ 각 카드팩당 들어있는 카드의 수
Pi:i번째 카드팩의 가격

- 변수 제한 사항
1 <= N <= 1,000
1 <= Pi <= 10,000

- 문제 상황
 각각의 카드팩의 가격이 주어졌을 때, N개의 카드를 구매하기 위해 지불해야하는 금액의 최솟값을 구하라

2. 풀이 계획

전체 문제를 N개의 카드를 구매하는 금액의 최소값이라 할 때,
부분 문제는 k개(1<=k<=N)의 카드를 구매하는 금액의 최소값이라 하면, 

이전 최소값들을 이용해 값을 구할 수 있다!

1장만 구매할 때는 무조건 P1을 구매해야 하므로, P1로 초기화 시킨 후, 

P1부터 PN까지의 카드팩을 구매했을 때를 모두 고려해줘야 할듯 하다!

3. 계획 검증
*/

int N;
int P[1001];

int dp[1001];

int solution() {
	dp[0] = 0;

	// 모든 카드팩에 대해 고려해주기
	for (int i = 1;i <= N;i++) {
		int cnt = 0;
		while (true) {
			// 범위를 벗어날 경우 빠져나가기
			if (cnt + i > N) {
				break;
			}
			// 현재 저장된 값과 이전 값을 활용한 값을 비교하여 더 작은 값으로 저장
			dp[cnt + i] = min(dp[cnt + i], dp[cnt] + P[i]);

			cnt++;
		}
	}

	return dp[N];
}

int main() {
	cin >> N;

	// 초기값을 최대값보다 더 큰 값으로 하여 갱신이 되도록 하기
	fill_n(dp, N + 1, 10001);

	for (int i = 1;i <= N;i++) {
		cin >> P[i];
	}

	cout << solution();
}