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

int preOrderedTree[10005];

void postOrder(int start, int end) {
	if (start >= end) return;

	int i = start + 1;
	for (i; i < end; i++)
		if (preOrderedTree[start] < preOrderedTree[i]) break;

	postOrder(start + 1, i);
	postOrder(i, end);
	cout << preOrderedTree[start] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0, x;

	while (cin >> preOrderedTree[n++]);

	postOrder(0, n - 1);

	return 0;
}