#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수열의 크기
A: 수열에 포함되는 수들

- 변수 제한 사항
N: 1~10
A: -10~10

- 문제 상황
규현이가 쓴 수를 A라고 하면, A[i]는 규현이가 i번째 쓴 수이다. 
- S[i][j]는 A[i]부터 A[j]까지 합이 0보다 크면 +, 0이면 0, 0보다 작으면 -이다. (i<=j) 

이 S 배열이 주어졌을 때, 규현이가 쓴 N개의 수 A를 구하라

2. 풀이 계획

- 재귀로 구현하되, 각 j번째 단계에서는 다음 단계를 거친다.
 1. j보다 작거나 같은 모든 i에 대해 S[i][j]와 이전 단계로부터 넘어온 합을 고려하여, 가능한 A[j]의 범위를 정한다.
 2. 가능한 범위에 대해 반복을 진행하여 재귀의 다음단계를 진행하되, 이 때 지정된 A[j]에 따라 결정된 합을 다음단계로 넘긴다.
 3. j가 N-1일 때 범위를 구하고, 그 중 가장 작은수(아무거나 상관 없지만)를 출력하고 재귀를 종료한다.

3. 계획 검증


*/

int N;
char S[10][10];
vector<int>A;
int curSum[10];

// 하나 찾으면 종료
bool solution(int cur_j) {
	// 범위 구하기
	int maxNum = +10;
	int minNum = -10;

	for (int i = 0; i <= cur_j; i++) {
		// curSum + A[j] > 0
		if (S[i][cur_j] == '+') {
			// A[j] > -curSum
			minNum = max(minNum, -curSum[i] + 1); // 각 조건별로는 and관계이므로 더 좁은 범위 적용!
		} // curSum + A[j] = 0
		else if (S[i][cur_j] == '0') {
			// A[j] = -curSum 
			minNum = max(minNum, -curSum[i]);
			maxNum = min(maxNum, -curSum[i]);
		}
		else { // curSum + A[j] < 0
			// A[j] < -curSum
			maxNum = min(maxNum, -curSum[i] - 1); // 각 조건별로는 and관계이므로 더 좁은 범위 적용!
		}
	}

	//cout << "cur_j: " << cur_j << endl;
	//cout << "maxNum: " << maxNum << endl;
	//cout << "minNum: " << minNum << endl;
	//for (int i = 0; i < A.size(); i++) {
	//	cout << "curSum[" << i << "]: " << curSum[i] << endl;
	//}
	//cout << "A: ";
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	//cout << endl;

	// 종료 조건
	if (cur_j == N - 1) {
		if (maxNum >= minNum) {
			A.push_back(minNum);
			for (int i = 0; i < A.size(); i++) {
				cout << A[i] << " ";
			}

			return true;
		}
		else {
			return false;
		}
	}

	// 범위에 따른 반복 진행
	for (int i = minNum; i <= maxNum; i++) {
		// 제대로 된 수열을 발견하였을 때만 종료
		A.push_back(i);
		for (int j = 0; j < A.size(); j++) {
			curSum[j] += i;
		}
		if (solution(cur_j + 1)) {
			return true;
		}
		for (int j = 0; j < A.size(); j++) {
			curSum[j] -= i;
		}
		A.pop_back();
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> S[i][j];
		}
	}

	solution(0);
}