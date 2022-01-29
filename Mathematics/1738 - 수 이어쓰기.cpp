#include<iostream>
#include<cmath>
using namespace std;

/*
1. ���� �м�
- ����
N: �� ��

- ���� ���� ����
N: 1~100,000,000

- ���� ��Ȳ
1���� N���� �̾ �� ���� �ڸ����� ���Ͽ���

2. Ǯ�� ��ȹ
n�ڸ��� ���� 1�� �ڸ����� �����ϸ� 10^n - 10^n���� �����Ѵ�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N;

int solution() {
	int answer = 0;

	int digits = 1;

	while (true) {
		if (N / (int)pow(10, digits) == 0) {
			// ���� �ڸ����� ������ �������� ���� ���� ���� ������ ����
			N -= (int)pow(10, digits - 1) - 1;
			answer += N * digits;
			break;
		}
		else {
			// n�ڸ����� ����: 10^n - 10^(n-1)
			answer += ((int)pow(10, digits) - (int)pow(10, digits - 1)) * digits;
		}
		digits++;
	}

	return answer;
}

int main() {
	cin >> N;

	cout << solution();
}