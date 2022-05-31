#include<iostream>
#include<string>
#include<vector>
using namespace std;

// LCS를 구하기 위한 배열
int dp[1001][1001] = { {0, } };

// 값을 입력받을 문자열
string string1;
string string2;

void solution() {
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

	cout << dp[string2.length()][string1.length()] << '\n';

	vector<char> LCS;

	int i = string2.length();
	int j = string1.length();;
	while (i != 0 && j != 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			LCS.push_back(string2[i - 1]);
			i--;
			j--;
		}
	}

	for (int i = LCS.size() - 1; i >= 0; i--) {
		cout << LCS[i];
	}
}

int main() {
	cin >> string1;
	cin >> string2;

	solution();

	return 0;
}
