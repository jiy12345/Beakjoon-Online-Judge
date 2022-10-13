#include <iostream>
using namespace std;

long long G, A, T, D;

long long sumOfPow(long long base, long long exp) {
	long long resultNum = 1;
	for (long long i = 0; i < exp + 1; i++) {
		resultNum *= base;
	}
	resultNum -= 1;

	return resultNum / (base - 1);
}

void solution() {
	long long numOfGames = 0;
	long long numOfteamsToAdd = 0;

	// 더해져야 하는 팀의 수 구하기
	long long numOfPow = 0;
	long long curNum = 1;
	while (true) {
		if (curNum >= G * A + D) break;
		numOfPow++;
		curNum <<= 1;
	}

	numOfteamsToAdd = curNum - (G * A + D);

	numOfGames = G * (T * (T - 1) / 2) + sumOfPow(2, numOfPow - 1);

	cout << G << "*" << A << "/" << T << "+" << D << "=" << numOfGames << "+" << numOfteamsToAdd << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> G >> T >> A >> D;
		if (G == -1 && T == -1 && A == -1 && D == -1) break;

		solution();
	}
}