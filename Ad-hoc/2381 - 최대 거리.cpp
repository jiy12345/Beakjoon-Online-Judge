#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수

- 변수 제한 사항
문자열의 길이: 1 ~ 500,000

- 문제 상황
팰린드롬이 아닌 가장 긴 부분 문자열의 길이를 출력한다. 그런 부분 문자열이 없으면 -1을 출력한다.

2. 풀이 계획
팰린드롬이 아닌!

어떻게 찾아야 할까?

일단 가장 쉽게 떠올릴 수 있는 방법은 모든 경우의 수를 다 조사하는 것이다. 그런데 모든 경우의 수는 상당히 많으므로 시간 내에 조사할 수 없다.

AAA

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N;

int solution() {
	int minusMax = -2000001, minusMin = 2000001;
	int plusMax = -2000001, plusMin = 2000001;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		int minus = b - a;
		int plus = b + a;
		minusMin = min(minusMin, minus);
		minusMax = max(minusMax, minus);
		plusMin = min(plusMin, plus);
		plusMax = max(plusMax, plus);
	}

	return max(minusMax - minusMin, plusMax - plusMin);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution();
}