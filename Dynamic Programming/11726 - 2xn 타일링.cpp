#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
n: 2xn 크기의 직사각형의 크기를 나타내줄 변수

- 변수 제한 사항
n: 1~1,000

- 문제 상황
 2xn 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하라


2. 풀이 계획
 2xn 크기의 직사각형을 채운다고 했을 때, 이의 경우의 수를 구한다고 하면 가장 끝인 n에서 시작했을 때 갈 수 있는 방향은 2가지 뿐이다.

 크기가 2xn이므로, 가로로 놓인 타일이 비틀려 있거나 한 경우는 나올 수가 없으므로 앞서 말한 두가지만 고려하면 된다.

따라서 재귀적으로 구현하여 N에서 N-1과 N-2일때의 경우의 수를 더하면 될듯 하다.


따라서 자세한 계획은 다음과 같다.
1. n이 1, 2일 때의 경우의 수는 각각 1, 2이므로 이를 입력해놓는다.
2. n을 입력받고, 계산된 사항이 있을 때까지 재귀적으로 구현한다.
*/

int num_of_cases[1001] = { 0, };

int solution(int n) {
	if (num_of_cases[n] != 0) {
		return num_of_cases[n];
	}
	else {
		num_of_cases[n] = solution(n - 1) + solution(n - 2) % 10007;
		return num_of_cases[n];
	}

	
}

int main() {
	// 초기값 입력
	num_of_cases[1] = 1;
	num_of_cases[2] = 2;

	int n;
	
	cin >> n;
	
	cout << (solution(n) % 10007);
}