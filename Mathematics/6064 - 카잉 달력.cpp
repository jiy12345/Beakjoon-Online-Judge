#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
<M:N>: ī�� �޷��� ������ ��
<x:y>: ������ �˾Ƴ����� ��

- ���� ���� ����
N, M: 1~40,000
x: 1~M
y: 1~N

- ���� ��Ȳ
  ù ��° ��: <1:1>
  �� ��° ��: <2:2>
  <x:y>�� ���� ��: <x':y'>  x < M �̸� x' = x + 1�̰�, �׷��� ������ x' = 1
                           y < N �̸� y' = y + 1�̰�, �׷��� ������ y' = 1
  <M:N>: �޷��� ������ ��

2. Ǯ�� ��ȹ

������ ������ ������ ǥ���� ���� k�� �� ��,

 ������ x���� k�� M���� ���� ������
 ������ y���� k�� N���� ���� ������

 M:N�� MxN�̴�!

 ���� MxN �̳��� 

 k�� M���� ���� �������� x�� �Ǹ�, k�� N���� ���� �������� y�� �Ǵ� k�� ���ϴ� ���� ��ǥ��� �� �� �ִ�!

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int M, N;
int x, y;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	
	int n;

	while (b != 0) {
		n = a % b;
		
		a = b;
		b = n;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int solution() {
	if (y == N) y = 0;
	int maxNum = lcm(M, N);

	for (int i = x; i <= maxNum; i += M)
		if (i % N == y) return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;

		cout << solution() << '\n';
	}

}