#include<vector>
#include<iostream>
using namespace std;

void solution(int T) {
	// 규칙성을 보이지 않는 7항까지는 미리 저장하기
	vector<long long> P = { 1, 1, 1, 2, 2, 3, 4 };

	// 8항부터 100항까지는 계산하여 구하기
	for (int i = 7; i < 100; i++) {
		P.push_back(P[i - 1] + P[i - 5]);
		P[i];
	}

	int N;

	// 요청받은 위치의 항 출력
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << P[N - 1] << endl;
	}
}

int main() {
	int T;

	cin >> T;

	solution(T);

	return 0;
}
