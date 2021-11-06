#include<iostream>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
 n: ���� ������ ��
 k: ���Ϸ��� ��ġ�� ��

- ���� ���� ����
 n: 1~100
 k: 1~10,000

 �� ������ ��ġ: 1~100,000

 ��ü ����� ���� ����: 2^31���� ���� => int������ ��Ÿ�� �� ����!

- ���� ��Ȳ
 k�� �� ������ ��ġ�� �־��� ��, k�� ������ �� �ִ� ����� ���� ���Ͽ���.

2. Ǯ�� ��ȹ
 - ��ü ����: k�ݾ��� ����� ����� ��
 - �κ� ����: n(1 <= n < k) n�ݾ��� ����� ����� ��

n �ݾ��� ����� ����� ���� ������ ���� ����ŭ �����Ѵ�.

�� ������ ��ġ�� ���� ����ŭ�� ���� �����ϴ� ���̴�.

 ���� ��ȭ������ �Ẹ�� ������ ����.

 dp[n] = dp[n-1] + 2*dp[n-2]
 

3. ��ȹ ����


*/

// k �ݾ��� ����� ���� ����� ��
int dp[10001] = { 0, };

int coin[100] = { 0, };

int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}


int solution(int n, int k) {
	

	return dp[n] = 0;
}


int main() {
	int n, k;

	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n);

	cout << solution(n, k);

	return 0;
}
