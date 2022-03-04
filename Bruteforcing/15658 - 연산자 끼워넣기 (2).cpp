#include<iostream>
#include<vector>
using namespace std;


/*
1. ���� �м�
- ����
N: ������ ���Ե� ���� ����

- ���� ���� ����
N: 2 ~ 11
�߰� ���� ����� ������ ��� ���� ����� -10�� ~ 10�� �����̴�
�� ��Ģ�������� ����: N-1 ~ 4N

- ���� ��Ȳ
 �� ��Ģ�������� ������ �־����� ��, ���� �ִ밪�� �ּҰ��� ���Ͽ���.


2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

enum{PLUS, MINUS, MULTIYPLY, DIVIDE, OPER_NUM};

int N;
int operands[11];
int numOfOperator[4];

int minNum, maxNum;

void solution(int numToDraw, int curResult) {
	if (numToDraw == 0) {
		minNum = min(minNum, curResult);
		maxNum = max(maxNum, curResult);
		return;
	}

	for (int i = 0; i < OPER_NUM; i++) {
		if (numOfOperator[i] == 0) {
			continue;
		}

		numOfOperator[i]--;
		switch (i) {
		case PLUS:
			solution(numToDraw - 1, curResult + operands[N - numToDraw]);
			break;		
		case MINUS:
			solution(numToDraw - 1, curResult - operands[N - numToDraw]);
			break;		
		case MULTIYPLY:
			solution(numToDraw - 1, curResult * operands[N - numToDraw]);
			break;		
		case DIVIDE:
			solution(numToDraw - 1, curResult / operands[N - numToDraw]);
			break;
		}
		numOfOperator[i]++;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> curPermutation;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> numOfOperator[i];
	}

	maxNum = -1000000000;
	minNum = 1000000000;

	solution(N - 1, operands[0]);

	cout << maxNum << '\n';
	cout << minNum << '\n';

	return 0;
}