#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
1. 문제 분석

- 변수
N: 양의 정수

- 변수 제한 사항
2 <= N <= 1,000,000


 - 문제 상황
각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 출력한다.

2. 풀이 계획
매번 뒤집으며 반복을 진행하면 상당히 오래 걸릴것이다!

따라서 is_reversed 변수를 선언하여 뒤집힌 상태인지 똑바로 된 상태인지 를 표시하고

수를 하나 버릴때는 뒤집힌 상태라면 앞에서 하나를 버리고, 뒤집히지 않은 상태라면 뒤에서 하나를 버린다!
 => 앞 뒤에서 모두 삭제가 이루어지므로 deque를 사용하는 것이 효율적일 듯 하다!
마지막에는 뒤집힌 상태라면 뒤집어서 출력한다!

1. 테스트 케이스 변수를 입력받는다.
2. 테스트 케이스 변수의 크기만큼 반복문을 돌리며, AC와 배열을 입력받는다.
3. 배열을 입력받을 때는  2n+1(대괄호와 쉼표를 포함하여) 개의 문자를 읽어 정수면 벡터에 저장하도록 한다.


다음과 같은 과정을 거치자


3. 계획 검증

*/


void solution(int T) {
	
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;


		int prime_factor = 2;
		int cnt = 0;
		while (true) {
			if (N % prime_factor == 0) {
				N /= prime_factor;
				cnt++;
			}
			else {
				if (cnt != 0) {
					cout << prime_factor << " " << cnt << "\n";
					cnt = 0;
				}
				prime_factor++;
			}
			if (N == 1) {
				if (cnt != 0) {
					cout << prime_factor << " " << cnt << "\n";
					cnt = 0;
				}
				break;
			}
		}
	}
}

int main() {
	int T; // ATM에 줄 서있는 사람의 수

	cin >> T;

	solution(T);

	return 0;
}
