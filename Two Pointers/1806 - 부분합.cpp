#include<iostream>
using namespace std;


/*
1. 문제 분석
- 변수
N: 수열의 수의 개수
S: 목표로 하는 합

- 변수 제한 사항
N: 1 ~ 10,000
M: 1 ~ 100,000,000
수열에 포함된 수: 1 ~ 10,000

- 문제 상황
 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를 구하여라

2. 풀이 계획

일단 10,000이 입력의 최대 크기이므로, 무작정 처음부터 돌리는 것은 불가능하다.

따라서 다음 순열을 실제 구해야 하는데, 다음 순열이라는 것은 어떻게 표현할까?

=> 정렬되는 과정이라고 볼 수도 있겠다.

3. 계획 검증


*/

int A[100001];
int N, S;

int solution() {
	int answer = N + 1;

	int sum = A[0];
	int i = 0;
	int j = 0;

	while (true) {
		if (sum >= S) {
			// 하나의 수가 S 이상일 경우
			if (i == j)  return 1;
			answer = min(answer, j - i + 1);
			sum -= A[i++];
		}
		else {
			sum += A[++j];
		}

		if (i >= N || j >= N) break;
	}

	if (answer == N + 1) answer = 0;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution();
}