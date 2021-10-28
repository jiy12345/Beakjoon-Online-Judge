#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
 N: ��� ���� ����

- ���� ���� ����
N: 1~100

- ���� ��Ȳ
 ������ ��� �ڸ��� ���̰� 1�� ���� ��ܼ���� �Ѵ�.

N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���Ͽ���

2. Ǯ�� ��ȹ
�� ���� ��(1~9)���� ��� ���� ����� ���� ���ϸ� �� �� �ϴ�!

���ؾ� �ϴ� ��
��� ��� ���� ����� ��

�κ� ����
�� ������ġ�� ���� ��� ���� ����� ��

�κ� ������ �κ� ����
�� ��ġ���� ���� ���� ����� ��



*/

// �� ��ġ�� ���� ���� ����� ��
long long dp[10][100] = { {0,}, };

int N; // ����� ����

// cur_index: �� ��ġ�� �ε��� 
// cur_num: �� ��ġ�� ��
long long solution(int cur_index, int cur_num) {
	// ���� ���
	if (cur_index == N - 1) {
		return 1;
	}

	// �̹� ����� ���� ���� ��� �״�� ����
	if (dp[cur_num][cur_index] != 0) {
		return dp[cur_num][cur_index];
	}

	// 0�� ��� ���� ���� ������ 1�̾�� ��
	if (cur_num == 0) {
		dp[cur_num][cur_index] = solution(cur_index + 1, 1) % 1000000000;
		return dp[cur_num][cur_index];
	}
	// 9�� ��� ���� ���� ������ 8�̾�� ��
	else if (cur_num == 9) {
		dp[cur_num][cur_index] = solution(cur_index + 1, 8) % 1000000000;
		return dp[cur_num][cur_index];
	}
	// ������ ��� �� �Ʒ� ��η� ���� ����
	else {
		dp[cur_num][cur_index] = ((solution(cur_index + 1, cur_num + 1)% 1000000000) + (solution(cur_index + 1, cur_num - 1)%1000000000))% 1000000000;
		return dp[cur_num][cur_index];
	}
}

int main() {
	cin >> N;

	long long answer = 0;

	for (int i = 1;i < 10;i++) {
		answer += (solution(0, i) % 1000000000);
	}

	cout << answer%1000000000;
}

