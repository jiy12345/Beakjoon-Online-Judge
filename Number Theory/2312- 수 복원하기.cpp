#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void solution(int T) {
	
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		// 소인수가 될 수 있는 가장 작은 수인 2부터 시작
		int prime_factor = 2;
		int cnt = 0;
		while (true) {
			// 나눠질 경우 나누고 현재 소인수의 개수 +1
			if (N % prime_factor == 0) {
				N /= prime_factor;
				cnt++;
			}
			else { // 더이상 현재 소인수로 나누어지지 않을 경우 소인수와 소인수 개수 출력하고 다음 수로
				if (cnt != 0) { // 한 개 이상 발견된 소인수에 대해서만 출력 진행
					cout << prime_factor << " " << cnt << "\n";
					cnt = 0;
				}
				prime_factor++;
			}
			if (N == 1) { // 다 나누어져 더이상 나눌 수 없을 경우
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
	int T; // 테스트 케이스의 수

	cin >> T;

	solution(T);

	return 0;
}
