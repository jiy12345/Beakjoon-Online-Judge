#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
1. 문제 분석
- 변수
N: 배열이 가진 수의 개수

- 변수 제한 사항
N, M: 3~8

- 문제 상황
배열에 들어있는 정수의 순서를 적절히 바꿔 다음 식의 계산 결과를 최대로 하는 수열의 값을 구하여라

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

2. 풀이 계획

 순서가 상관있는 배치이므로, 순열 문제이고, N개중 N개를 뽑는 문제이다.

 재귀로 구현하되, 마지막에 값만 계산해주면 될 듯 하다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N;
int maxNum = -100 * 8;
int sequence[8];  // 입력받은 수열 저장
bool isPicked[8]; // 뽑힌 수인지 체크
vector<int>subSequence; // 배치한 수열

void permutation() {
	int curSize = subSequence.size();
	if (curSize == N) {
		int curNum = 0;
		for (int i = 0; i < curSize - 1; i++) {
			curNum += abs(subSequence[i] - subSequence[i + 1]);
		}

		maxNum = max(maxNum, curNum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isPicked[i] == false) {
			subSequence.push_back(sequence[i]);
			isPicked[i] = true;
			permutation();
			subSequence.pop_back();
			isPicked[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}

	permutation();

	cout << maxNum;
}