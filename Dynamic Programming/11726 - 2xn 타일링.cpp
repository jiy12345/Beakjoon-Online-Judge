#include<iostream>
using namespace std;

// 각 위치의 경우의 수
int num_of_cases[1001] = { 0, };

int solution(int n) {
	// 이미 저장된 값이 있을 경우
	if (num_of_cases[n] != 0) {
		return num_of_cases[n];
	}
	else {
		// 모듈러 연산의 개념 적용 (a + b) % c = (a % c + b % c) % c
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
	
	// 모듈러 연산의 개념 적용 (a + b) % c = (a % c + b % c) % c
	cout << (solution(n) % 10007);
}
