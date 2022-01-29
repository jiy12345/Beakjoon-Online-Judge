#include<iostream>
#include<cmath>
using namespace std;

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
