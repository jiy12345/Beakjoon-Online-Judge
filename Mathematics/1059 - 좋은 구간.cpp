#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
S: 정수의 집합
L: S의 크기
n: 목표 수

- 변수 제한 사항
 L: 1 ~ 50
 S에는 중복되는 정수가 없다.
 집합 S에 포함된 모든 정수는 1보다 크거나 같고, 1,000보다 작거나 같다.
 
 n은 집합 s에 있는 수 범위 내에 있다.

- 문제 상황
정수 집합 S가 주어졌을때, 다음 조건을 만족하는 구간 [A, B]를 좋은 구간이라고 한다.

A와 B는 양의 정수이고, A < B를 만족한다.
A ≤ x ≤ B를 만족하는 모든 정수 x가 집합 S에 속하지 않는다.

집합 S와 n이 주어졌을 때, n을 포함하는 좋은 구간의 개수를 구해보자.

2. 풀이 계획
 n이 속하는 좋은 구간의 개수는 다음과 같이 계산할 수 있다.

1. 집합 S를 정렬한다.
2. n이 집합 S의 어떤 수 a와 어떤 수 b 사이에 있는지 체크한다.
3. a + 1 부터 n까지 수 k를 하나씩 뽑아 반복하며, (b-1) - k를 더한다. 

- 종료 조건의 체크
 위의 처리가 모두 끝난 뒤, 머리(가장 앞)가 있는 칸이 벽 또는 자기 자신일 경우 게임 종료

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define MAX 50

int S[MAX];
int L, n;

int solution() {
	sort(&S[0], &S[L]);

	// n이 포함되는 구간 찾기
	int prevNum = 0;
	int nextNum = 0;
	for (int i = 0; i < L; i++) {
		// n S에 포함되는 경우 n이 속하는 좋은 구간이 나올 수 없음
		if (S[i] == n) return 0;
		if (S[i] > n) {
			nextNum = S[i];
			prevNum = S[i - 1];
			break;
		}
	}

	// 좋은 구간의 개수 구하기
	int answer = 0;
	for (int k = prevNum + 1; k <= n; k++) {
		answer += (nextNum - 1) - max((n - 1), k);
	}
	return answer;
}

void input() {
	cin >> L;

	for (int i = 0; i < L; i++)
		cin >> S[i];

	cin >> n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	cout << solution();
}