#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
 n: 계산의 목표가 되는 n
 T: 테스트 케이스의 개수

- 변수 제한 사항
 N: 1~10

- 문제 상황
각 테스트 케이스마다 n을 1, 2, 3으로 나타내는 방법의 수를 출력한다.

2. 풀이 계획
 이 문제는 정수의 크기가 매우 작으므로 미리 다 계산해놓은 후 진행하여도 되지만, 
 메모이제이션을 이용하도록 하자

메모이제이션(memoization)이란, 컴퓨터 프로그램이 동일한 계산을 반복해야 할 때 이전에 계산한 값을 메모리에 저장함으로써 동일한 계산의 반복 수행을 제거하여 프로그램의 실행속도를 빠르게 하는 기술이다.

이 문제에서는 a + b = c라고 했을 때, a와 b를 만들 수 있는 경우의 수가 c를 만들 수 있는 경우의 수에 모두 포함되므로, 각각의 수를 만들 수 있는 경우의 수를 저장해놓으면 계산을 조금 더 효율적으로 진행할 수 있을 듯 하다.

순서가 상관이 있으므로, 모든 경우의수를 다 고려해도 될 듯함!

값과 경우의 수를 명확히 구분하여 생각하자!

=> 처음에는 1을 빼는 것 또한 하나의

3. 계획 검증

*/

int calculated_value[11] = { 0, };

int solution(int N) {
	// 이미 경우의 수가 모두 계산된 수의 경우
	if (calculated_value[N] != 0) {
		return calculated_value[N];
	}
	else {
		// 다음 연산을 위해 저장
		calculated_value[N] = solution(N - 1) + solution(N - 2) + solution(N - 3);
		return calculated_value[N];
	}
}


int main() {
	int N, T;

	cin >> T;

	calculated_value[1] = 1; // 1
	calculated_value[2] = 2; // 1+1, 2
	calculated_value[3] = 4; // 1+1+1, 1+2, 2+1, 3

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << solution(N) << endl;
	}

}