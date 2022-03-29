#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
1. ���� �м�
- ����
N: ��ü ����� ��

- ���� ���� ����
N: 2 ~ 100,000
����� Ư�� ��: -1,000,000,000 ~ 1,000,000,000

����� Ư�������� ���ĵ� ���·� �־���


- ���� ��Ȳ
 Ư������ 0�� ���� ����� ����� ������ �� ����� Ư������ ���϶�

2. Ǯ�� ��ȹ
�ܼ��� 1�� ������Ű�鼭 ������ �� �� �ϴ�


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

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

		// ���ŵ� ���
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