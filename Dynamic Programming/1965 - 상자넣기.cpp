#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
S: ���� �̸�Ƽ���� ����

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

int dp[1000] = { 0, };
// ���� �Է¹��� �迭
int A[1000] = { 0, };

int n; // ������ ����

int solution() {
    int answer = 0;
    dp[0] = 1;
    for (int i = 0;i < n;i++) {
        dp[i] = 1;
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(dp[i], answer);
    }
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}

	cout << solution();
}