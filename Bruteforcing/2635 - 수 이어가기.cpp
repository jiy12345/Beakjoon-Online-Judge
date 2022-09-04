#include<iostream>
using namespace std;

int N;
int sequence(int secondNum, bool isPrint) {
	int curNum = N;
	int i = 0;
	while (curNum >= 0) {
		int temp = curNum;
		if (isPrint) cout << temp << ' ';
		curNum = secondNum;
		secondNum = temp - secondNum;
		i++;
	}
	return i;
}

void solution() {
	int maxLength = 0;
	int maxSecondNum = 0;
	for (int i = N / 2; i <= N; i++) {
		int a = sequence(i, false);
		if (maxLength < a) {
			maxLength = a;
			maxSecondNum = i;
		}
	}

	cout << maxLength << '\n';
	sequence(maxSecondNum, true);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();

	return 0;
}