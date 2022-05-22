#include<iostream>
#include<string>
using namespace std;

#define MAX 4001

// LCS�� ���ϱ� ���� �迭
int dp[MAX][MAX];

// ���� �Է¹��� ���ڿ�
string string1;
string string2;

int LCS() {
	int answer = 0;

	for (int i = 1; i <= string2.length(); i++) {
		for (int j = 1; j <= string1.length(); j++) {
			// �� ���ڿ��� ������ ��ġ�� ���ڰ� ���� ���
			if (string1[j - 1] == string2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // ���� ���� ���
				dp[i][j] = 0;
			}
			answer = max(answer, dp[i][j]);

		}
	}

	return answer;
}

int main() {
	cin >> string1;
	cin >> string2;

	cout << LCS();

	return 0;
}