#include<iostream>
#include<cmath>
using namespace std;

/*
1. 문제 분석
- 변수
N: 끝 수

- 변수 제한 사항
N: 1~100,000,000

- 문제 상황
1부터 N까지 이어서 쓴 수의 자리수를 구하여라

2. 풀이 계획
n자리수 수는 1의 자리수만 제외하면 10^n - 10^n개가 존재한다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N;

int solution() {
	int answer = 0;

	int digits = 1;

	while (true) {
		if (N / (int)pow(10, digits) == 0) {
			// 이전 자리수의 마지막 수까지를 빼면 남은 수의 개수가 나옴
			N -= (int)pow(10, digits - 1) - 1;
			answer += N * digits;
			break;
		}
		else {
			// n자리수의 개수: 10^n - 10^(n-1)
			answer += ((int)pow(10, digits) - (int)pow(10, digits - 1)) * digits;
		}
		digits++;
	}

	return answer;
}

int main() {
	cin >> N;

	cout << solution();
}