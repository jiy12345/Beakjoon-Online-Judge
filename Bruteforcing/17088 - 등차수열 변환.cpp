#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수열 B의 크기


- 변수 제한 사항
Bi: 1 ~ 10^9
N: 1 ~ 10^5


- 문제 상황
두 수 A, B가 주어지고, 가능한 연산이 다음과 같다고 할 때,

2를 곱한다.
1을 수의 가장 오른쪽에 추가한다.

A를 B로 바꾸는데 필요한 연산의 최소값을 구하여라.
바꿀 수 없을 경우 -1을 출력한다.

2. 풀이 계획

1. bfs를 진행하되

방문 표시를 bool형으로 진행하면 1기가바이트가 필요하다. 어떻게 처리할 수 있을까?

- 연산 1: 비트 연산 <<로 구현 가능
=> 연산 1의 결과는 항상 짝수이다.
- 연산 2: 수에 10을 곱한 후 1 더하는 것으로 구현 가능
=> 연산 2의 결과는 항상 홀수이다.

=> 가능한 두 연산이 모두 수가 커지는 연산이므로, B이상으로 진행할 필요가 없다.



3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define MAX 1000000000

int N, B[100000], ans = MAX;

void dfs(int prevValue, int idx, int cnt, int r) {
	if (cnt >= ans) return;
	if (idx >= N) {
		ans = min(cnt, ans);
		return;
	}
	if (B[idx] - prevValue == r) dfs(B[idx], idx + 1, cnt, r);
	if (B[idx] - 1 - prevValue == r) dfs(B[idx] - 1, idx + 1, cnt + 1, r);
	if (B[idx] + 1 - prevValue == r) dfs(B[idx] + 1, idx + 1, cnt + 1, r);
}

int solution() {
	// 가능한 시작 숫자와 동차에 따라 반복
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			dfs(B[1] + i, 2, (i != 0) + (j != 0), (B[1] + i) - (B[0] + j));
	
	return (ans != MAX) ? ans : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> B[i];

	cout << solution();
}