#include<iostream>
#include<string>
using namespace std;

bool isAbnormal[10];
int N, M;

int solution() {
	int end = abs(N - 100);
	int answer = end;

	for (int i = 0; i < end; i++) {
		string numPlus = to_string(N + i);
		string numMinus = to_string(N - i);

		int j = 0;

		if (stoi(numMinus) >= 0) {
			int numMinusLength = numMinus.size();

			for (j = 0; j < numMinusLength; j++) {
				if (isAbnormal[numMinus[j] - 48]) {
					break;
				}
			}

			if (j == numMinusLength) {
				answer = min(answer, (numMinusLength + i));
				break;
			}
		}

		if (stoi(numPlus) <= 1000000) {

			int numPlusLength = numPlus.size();

			for (j = 0; j < numPlusLength; j++) {
				if (isAbnormal[numPlus[j] - 48]) {
					break;
				}
			}

			// 모든 수가 누를 수 있는 수일 때
			if (j == numPlusLength) {
				answer = min(answer, (numPlusLength + i));
				break;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;

		cin >> num;

		isAbnormal[num] = true;
	}

	cout << solution();
}
