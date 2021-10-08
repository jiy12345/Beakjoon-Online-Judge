#include<iostream>
using namespace std;

int solution(int N) {
	int answer = 0;

	// 팩토리얼 연산에서 곱해질 모든 수들을 소인수 분해
	// 소인수 분해하였을 때 2와 5의 개수 세기
	int num_of_two = 0;
	int num_of_five = 0;

	for (int i = 1; i <= N; i++) {
		int temp = i;
		// 2 찾기
		while (temp % 2 == 0) {
			temp /= 2;
			num_of_two++;
			if (temp == 0) {
				break;
			}
		}
		// 5찾기
		while (temp % 5 == 0) {
			temp /= 5;
			num_of_five++;
			if (temp == 0) {
				break;
			}
		}
	}

	// 2와 5가 곱해져 10이 되므로 둘 중 적은 수가 0의 개수(10이 곱해진 수)가 됨
	answer = min(num_of_five, num_of_two);

	return answer;
}

int main() {
	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}
