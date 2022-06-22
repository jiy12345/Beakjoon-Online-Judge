#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수 제한 사항
주어지는 자연수: 1~10,000

- 문제 상황
주어진 두 수의 최대 공약수와 최소 공배수를 구하라

2. 풀이 계획
 유클리드 호제법으로 최대 공약수를 구한 뒤, 두 수를 곱한 수를 최대공약수로 나누오 최소 공배수를 구한다!

3. 계획 검증

*/

int numPrimeFactor(int n, int primeFactor) {
	int numPrimeFactor = 0;

	for (long long i = primeFactor; n / i >= 1; i *= primeFactor) {
		numPrimeFactor += n / i;
	}

	return numPrimeFactor;
}

int solution(int n, int m) {
	int numOfFive = 0;
	int numOfTwo = 0;

	numOfFive = numPrimeFactor(n, 5) - numPrimeFactor(n - m, 5) - numPrimeFactor(m, 5);
	numOfTwo = numPrimeFactor(n, 2) - numPrimeFactor(n - m, 2) - numPrimeFactor(m, 2);

	return min(numOfTwo, numOfFive);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	cout << solution(n, m);
}