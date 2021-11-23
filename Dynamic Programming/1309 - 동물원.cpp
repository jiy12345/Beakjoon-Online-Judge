#include<iostream>
#include<numeric>
using namespace std;

/*
1. ���� �м�
- ����
N: �츮�� ũ��


- ���� ���� ����
N: 1~100,000

- ���� ��Ȳ
���ڸ� ����, ���η� �ٿ��� ��ġ�� �� ���� �� ��, 2 * N ũ���� �츮�� ���ڸ� ��ġ�ϴ� ����� ���� 9901�� ���� �������� ����϶�!

2. Ǯ�� ��ȹ


 dp[k] = dp[k-1] + 2 * (dp[k-2] + dp[k-3] + ... dp[1] + 2)
*/


int dp[100000];

int N; // �츮�� ũ��

int solution() {
	dp[0] = 3;
	dp[1] = 7;

	for (int i = 2;i < N;i++) {
		//dp[i] = (dp[i - 1] + 2 * (accumulate(dp, dp + i - 1, 0) + 2)) % 9901;
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}

	return dp[N - 1];
}

int main() {
	cin >> N;

	cout << solution();

}