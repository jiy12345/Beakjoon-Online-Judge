#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
1. ���� �м�
- ����
N: �迭�� ���� ���� ����

- ���� ���� ����
N, M: 3~8

- ���� ��Ȳ
�迭�� ����ִ� ������ ������ ������ �ٲ� ���� ���� ��� ����� �ִ�� �ϴ� ������ ���� ���Ͽ���

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

2. Ǯ�� ��ȹ

 ������ ����ִ� ��ġ�̹Ƿ�, ���� �����̰�, N���� N���� �̴� �����̴�.

 ��ͷ� �����ϵ�, �������� ���� ������ָ� �� �� �ϴ�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N;
int maxNum = -100 * 8;
int sequence[8];  // �Է¹��� ���� ����
bool isPicked[8]; // ���� ������ üũ
vector<int>subSequence; // ��ġ�� ����

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