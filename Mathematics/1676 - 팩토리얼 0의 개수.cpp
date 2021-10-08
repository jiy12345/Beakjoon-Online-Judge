#include<iostream>
using namespace std;



/*
1. 문제 분석

- 변수
N: 팩토리얼 연산을 진행할 수

- 변수 제한 사항
0 <= N <= 500

 - 문제 상황
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하라!

2. 풀이 계획

500!을 계산하면, 1.22e+1134이라는 1134자리수가 나오게 된다. 따라서 계산해서 변수에 저장하는 것은 불가능하다!

따라서 반복문을 돌리며 곱하면서, 곱할 때마다 10으로 나눌 수 있을 때까지 나누며, 그 10으로 나눈 횟수를 세면 될 듯 하다!

=> 이런 방법도 자리수가 커지고 0의 개수는 그리 많지 않으므로 오버플로우가 발생하게 된다.

=> 따라서 곱하지 않고 각각의 수를 2와 5로 나누어 봐 2의 개수와 5의 개수를 세고, 더 작은 개수를 가진 수를 출력하면 10의 개수가 된다.



따라서 자세한 과정은 다음과 같다.

1. 1부터 N까지 반복하며, 각각을 2와 5로 나누어 봐 소인수 분해 하였을 때 2와 5가 몇개 있는 지 누적하여 센다.
2. 2와 5의 개수 중 적은 것의 개수가 10의 개수(2와 5가 곱해져야 10이 나오므로)를 최소값으로 하여 출력한다.

3. 계획 검증


*/


int solution(int N) {
	int answer = 0;

	int num_of_two = 0;
	int num_of_five = 0;

	for (int i = 1; i <= N; i++) {
		int temp = i;
		while (temp % 2 == 0) {
			temp /= 2;
			num_of_two++;
			if (temp == 0) {
				break;
			}
		}
		while (temp % 5 == 0) {
			temp /= 5;
			num_of_five++;
			if (temp == 0) {
				break;
			}
		}
	}

	answer = min(num_of_five, num_of_two);

	return answer;
}

int main() {
	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}