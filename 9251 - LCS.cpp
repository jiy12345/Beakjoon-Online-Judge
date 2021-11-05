#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�

- ���� ���� ����
���ڿ��� ����: �ִ� 1,000����
���ڿ��� ���ĺ� �빮�ڷθ� �̷������!

- ���� ��Ȳ
 �� ���ڿ��� �־��� ��, �� ���ڿ��� ���� ���� �κ� ������ ���Ѵ�!

2. Ǯ�� ��ȹ
 �κ� ������ ������ �����Ǹ�, �߰��� � ���� ������ ��� �����Ƿ�, ������ ���� ���غ��鼭 ������ ���� �ɵ� �ϴ�.

 �� �������� �� ��ġ���� ��ġ�� �͵��� �߰ߵ� ��쿡�� ���� ���ϰ�, �׷��� ���� ��� 

 �׷���, Ư�� ���� ������� �ʴ� ���� �� �ִ� ���̸� ���� �� �ִ� ��찡 �߻��� ���� �ִ�!

 ���� ��� ���ĺ����� �����ϴ� �Ϳ� ���� �õ� �ϰ�, �� 

 - ��ü ����: N ������ �� ���ڿ��� ���� �� ���ڿ��� ���� ���� �κ� ���� ���ϱ�!


*/


// LCS�� ���ϱ� ���� �迭
int dp[1001][1001] = { {0, } };

// ���� �Է¹��� ���ڿ�
string string1;
string string2;


int solution() {
	
	for (int i = 1;i <= string2.length();i++) {
		for (int j = 1;j <= string1.length();j++) {
			if (string1[j - 1] == string2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	//for (int i = 0;i < string2.length();i++) {
	//	for (int j = 0;j < string1.length();j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return dp[string2.length()][string1.length()];
}

int main() {
	cin >> string1;
	cin >> string2;

	cout << solution();

	return 0;
}