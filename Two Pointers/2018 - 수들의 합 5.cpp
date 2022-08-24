#include<iostream>
using namespace std;

int N;

int solution() {
	int frontNum = 1;
	int backNum = 1;
	int answer = 1; // N으로 나타내는 방법
	int curSum = 1;

	while (true) {
		if (backNum > N / 2 + 1 || backNum >= N) break;
		if (curSum < N) {
			curSum += ++backNum;
		}
		else {
			if (curSum == N) answer++;

			curSum -= frontNum++;
		}
	}

	return answer;
}

int main() {
	cin >> N;

	cout << solution();
}