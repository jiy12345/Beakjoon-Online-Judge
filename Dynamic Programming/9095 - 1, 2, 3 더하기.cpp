#include<iostream>
using namespace std;

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
