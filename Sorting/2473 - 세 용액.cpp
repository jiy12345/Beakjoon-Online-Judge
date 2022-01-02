#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
1. 문제 분석

- 변수
N: 용액의 수

- 변수 제한 사항
N: 3~5,000
용액의 특성 값: -1,000,000,000~1,000,000,000


 - 문제 상황
 용액의 특성값들이 주어질 때 특성값의 합이 0에 가장 가까운 용액을 만들어내는 세 용액의 특성값을 출력한다.

2. 풀이 계획


3. 계획 검증


*/

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