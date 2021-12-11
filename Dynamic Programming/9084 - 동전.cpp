#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
 T: 테스트 케이스의 개수
 N: 동전 종류의 수
 M: 동전으로 만들어야 할 금액

- 변수 제한 사항
 T: 1~10
 N: 1~20
 M: 1~10,000

방법의 수 2^31 - 1 보다 작다 => int형으로 나타낼 수 있다.
같은 가치의 동전이 여러번 주어지는 경우는 없다.

- 문제 상황
 동전의 가지 수와 각 동전의 금액이 오름차순으로 정렬되어 주어질 때, 동전으로 목표 금액을 만드는 모든 방법의 수를 구하여라

2. 풀이 계획
 순서에 상관 없이 뽑는 것이므로, 조합 문제이며, 조합 문제는 동전 순서대로 고려해 가는 것으로 판단을 진행한다!

*/

int T, N, M;

int coin[20];


int solution() {
	int dp[10001] = { 0, };

	// 딱 맞는 금액을 만들었다는 의미의 1
	dp[0] = 1;
	
	for (int i = 0;i < N;i++) {
		for (int j = coin[i];j <= M;j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	return dp[M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	for (int i = 0;i < T;i++) {
		cin >> N;

		for (int j = 0;j < N;j++) {
			cin >> coin[j];
		}

		cin >> M;

		cout << solution() << '\n';
	}
}