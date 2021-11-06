#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 n: 동전 종류의 수
 k: 구하려는 가치의 합

- 변수 제한 사항
 n: 1~100
 k: 1~10,000

 각 동전의 가치: 1~100,000

 전체 경우의 수의 개수: 2^31보다 작음 => int형으로 나타낼 수 있음!

- 문제 상황
 k와 각 동전의 가치가 주어질 때, k를 구성할 수 있는 경우의 수를 구하여라.

2. 풀이 계획
 - 전체 문제: k금액을 만드는 경우의 수
 - 부분 문제: n(1 <= n < k) n금액을 만드는 경우의 수

n 금액을 만드는 경우의 수는 동전의 종류 수만큼 존재한다.

각 동전의 가치를 빼준 수만큼의 수가 존재하는 것이다.

 따라서 점화식으로 써보면 다음과 같다.

 dp[n] = dp[n-1] + 2*dp[n-2]
 

3. 계획 검증


*/

// k 금액을 만들기 위한 경우의 수
int dp[10001] = { 0, };

int coin[100] = { 0, };

int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}


int solution(int n, int k) {
	

	return dp[n] = 0;
}


int main() {
	int n, k;

	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n);

	cout << solution(n, k);

	return 0;
}
