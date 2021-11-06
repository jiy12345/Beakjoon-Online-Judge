#include<iostream>
#include<string>
using namespace std;

// LCS를 구하기 위한 배열
int dp[1001][1001] = { {0, } };

// 값을 입력받을 문자열
string string1;
string string2;

int solution() {
	for (int i = 1;i <= string2.length();i++) {
		for (int j = 1;j <= string1.length();j++) {
			// 두 문자열의 마지막 위치의 문자가 같을 경우
			if (string1[j - 1] == string2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // 같지 않을 경우
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[string2.length()][string1.length()];
}

int main() {
	cin >> string1;
	cin >> string2;

	cout << solution();

	return 0;
}
