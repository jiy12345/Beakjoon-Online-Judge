#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����

- ���� ���� ����
���ڿ��� ����: 1 ~ 500,000

- ���� ��Ȳ
�Ӹ������ �ƴ� ���� �� �κ� ���ڿ��� ���̸� ����Ѵ�. �׷� �κ� ���ڿ��� ������ -1�� ����Ѵ�.

2. Ǯ�� ��ȹ
�Ӹ������ �ƴ�!

��� ã�ƾ� �ұ�?

�ϴ� ���� ���� ���ø� �� �ִ� ����� ��� ����� ���� �� �����ϴ� ���̴�. �׷��� ��� ����� ���� ����� �����Ƿ� �ð� ���� ������ �� ����.

AAA

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N;

int solution() {
	int minusMax = -2000001, minusMin = 2000001;
	int plusMax = -2000001, plusMin = 2000001;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		int minus = b - a;
		int plus = b + a;
		minusMin = min(minusMin, minus);
		minusMax = max(minusMax, minus);
		plusMin = min(plusMin, plus);
		plusMax = max(plusMax, plus);
	}

	return max(minusMax - minusMin, plusMax - plusMin);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution();
}