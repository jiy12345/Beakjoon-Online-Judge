#include<iostream>
#include<numeric>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����

- ���� ���� ����
N: 3~100
�־����� ���� 0~9

- ���� ��Ȳ
����̰� 0���� 20���� �ȴٰ� �� ��, +, - �� �־� ���� ������ �߰� ����� ������ ��� ����� ����̰� �ƴ� ���� ����� ���� ���Ͽ���

���� ���� 0���� 20������ �������� ���� ���� ǥ���� �����ϹǷ�,

2. Ǯ�� ��ȹ
 dp[i] = i+1��° ������ �������� ���� ����� ��

3. ��ȹ ����
*/

int num[100];

long long dp[100][21];
int N;


long long solution() {

	// ���� ù ���� ����!
	dp[0][num[0]] = 1;

	for (int i = 1;i < N - 1;i++) {
		for (int j = 0;j <= 20;j++) {
			if (j + num[i] <= 20) {
				dp[i][j + num[i]] += dp[i - 1][j];
			}
			if (0 <= j - num[i]) {
				dp[i][j - num[i]] += dp[i - 1][j];
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j <= 20;j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return dp[N - 2][num[N - 1]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> num[i];
	}

	cout<< solution();
}