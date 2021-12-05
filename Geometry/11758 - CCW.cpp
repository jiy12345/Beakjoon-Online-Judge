#include<iostream>
#include<cstring>
using namespace std;

/*
1. ���� �м�
- ����
P1, P2, P3: 2���� ��ǥ ��� ���� �� 3��


- ���� ���� ����
-1,000,000 �� x1, y1, x2, y2, x3, y3, x4, y4 �� 1,000,000
x1, y1, x2, y2, x3, y3, x4, y4�� ����

- ���� ��Ȳ
�ΰ��� ������ �� �������� �־��� ��, �� ���� �����ϴ��� �����϶�

2. Ǯ�� ��ȹy1
�ϴ� x ������ ��ġ�������� üũ�Ѵ�.

=> �׷����� �� ������ ��ġ���� ���� �����Ǿ�� �Ѵ�.
=> ��� ������ �� üũ�Ϸ��� 4���� ������ ����ְ� ��ġ�ؾ� �ϹǷ�, 4! = 24�̴�!

1. ��ġ�� ������ Ȯ��
L1�� ������ L2�� ������ ���ϰ�,
L2�� ������ L1�� ������ ���Ͽ�,
�� ��� ��� ������ Ŀ������ �����ִٰ� �� �� �ִ�.

2. ����� �Ǵ� ���� ���ϱ�
L1�� ������ L2�� ���� ���Ͽ� �� ���� �� ����
L1�� ������ L2�� ���� ���Ͽ� �� ū �� ����


3. ��ġ���� ���� Ȯ��
�� ������ ������ ���� ���ϰ�, �� ������ ���İ��� ������ ������ ��, �ռ� ���س��� ���� ���� ������ ���� ������ ��, �� ���� ���Ͽ� 0���� �۰ų� ������ Ȯ���Ѵ�!



3. ��ȹ ����
*/

int x1, y_1, x2, y2, x3, y3;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int result = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	if (result > 0) {
		return 1;
	}
	else if (result < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	cin >> x1 >> y_1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	cout << ccw(x1, y_1, x2, y2, x3, y3);
}