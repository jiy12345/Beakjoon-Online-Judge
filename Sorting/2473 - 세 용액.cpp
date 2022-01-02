#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N, M;
vector<int> values;

void solution() {
	long long answer = 3000000000;

	int curPtr[3];

	for (int i = 0; i < N - 2; i++) {
		long long firstValue = values[i];

		int leftPtr = i + 1;
		int rightPtr = N - 1;
		
		while (true) {
			long long curValue = firstValue + values[leftPtr] + values[rightPtr];

			// 갱신될 경우
			if (answer > abs(curValue)) {
				curPtr[0] = i;
				curPtr[1] = leftPtr;
				curPtr[2] = rightPtr;

				answer = abs(curValue);
			}

			if (curValue == 0) {
				cout << firstValue << " " << values[leftPtr] << " " << values[rightPtr];
				return;
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
	}

	cout << values[curPtr[0]] << " " << values[curPtr[1]] << " " << values[curPtr[2]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;

		values.push_back(value);

	}

	sort(values.begin(), values.end());

	solution();

	return 0;
}
