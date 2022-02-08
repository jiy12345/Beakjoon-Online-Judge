#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

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
