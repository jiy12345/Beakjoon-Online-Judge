#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
1. 문제 분석
- 변수
N: 전체 용액의 수

- 변수 제한 사항
N: 2 ~ 100,000
용액의 특성 값: -1,000,000,000 ~ 1,000,000,000

용액의 특성값들은 정렬된 상태로 주어짐


- 문제 상황
 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 구하라

2. 풀이 계획
단순히 1씩 증가시키면서 세보면 될 듯 하다


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


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