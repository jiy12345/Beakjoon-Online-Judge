#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
n: 1, 2, 3으로 나타내야 하는 수

- 변수 제한 사항
n:1~100,000

- 문제 상황
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력

2. 풀이 계획

문제가 되는 점: 조건을 고려한 것을 한번에 어떻게 나타낼 것이냐?

각 위치에서의 합은 원래는

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 이어야 하나, 각 조건에 따라 또 나뉘어져야 한다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

long long dp[1000001];

void solution(int maxNum) {

	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1, 2
	dp[3] = 4; // 1 + 1 + 1, 1 + 2, 2 + 1, 3

	for (int i = 4; i <= maxNum; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	vector<int>input;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		input.push_back(n);
	}

	solution(*max_element(input.begin(), input.end()));

	for (int i = 0; i < T; i++) {
		cout << dp[input[i]] << '\n';
	}

	return 0;
}