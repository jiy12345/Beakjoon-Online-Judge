#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
int values[100000];

void solution() {
	long long answer = 2000000000;

	int curPtr[2];

	int leftPtr = 0;
	int rightPtr = N - 1;

	while (true) {
		long long curValue = values[leftPtr] + values[rightPtr];

		// 갱신될 경우
		if (answer > abs(curValue)) {
			curPtr[0] = leftPtr;
			curPtr[1] = rightPtr;

			answer = abs(curValue);
		}

		if (curValue == 0) {
			break;
		}
		else if (curValue > 0) {
			rightPtr--;
		}
		else {
			leftPtr++;
		}

		if (leftPtr == rightPtr) {
			break;
		}
	}

	cout << values[curPtr[0]] << " " << values[curPtr[1]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> values[i];

	solution();

	return 0;
}
