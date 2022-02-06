#include<iostream>
#include<vector>
using namespace std;

// 수열의 길이
int N;
// 부호를 입력받을 배열
char S[10][10];
// 구한 수열을 저장할 벡터
vector<int>A;
// A[i] 부터 A[cur_j]까지의 합(현재 고려중인 단계까지의 합)
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

	// 종료 조건
	if (cur_j == N - 1) {
		// 범위 내에 수가 존재할 경우
		if (maxNum >= minNum) {
			A.push_back(minNum);
			for (int i = 0; i < A.size(); i++) {
				cout << A[i] << " ";
			}

			return true;
		}
		else { // 범위내에 수가 존재하지 않으면 찾지 못한 것!
			return false;
		}
	}

	// 범위에 따른 반복 진행
	for (int i = minNum; i <= maxNum; i++) {

		A.push_back(i);
		for (int j = 0; j < A.size(); j++) {
			curSum[j] += i;
		}
		// 제대로 된 수열을 발견하였을 때만 종료
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
