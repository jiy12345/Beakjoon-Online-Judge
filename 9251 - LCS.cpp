#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석

- 변수 제한 사항
문자열의 길이: 최대 1,000글자
문자열은 알파벳 대문자로만 이루어진다!

- 문제 상황
 두 문자열이 주어질 때, 두 문자열의 최장 공통 부분 수열을 구한다!

2. 풀이 계획
 부분 수열은 순서만 유지되며, 중간에 어떤 수가 들어가든지 상관 없으므로, 각각의 수를 비교해보면서 개수를 세면 될듯 하다.

 이 과정에서 각 위치에서 겹치는 것들이 발견될 경우에만 값을 더하고, 그렇지 않을 경우 

 그러나, 특정 수를 사용하지 않는 것이 더 최대 길이를 얻을 수 있는 경우가 발생할 수도 있다!

 따라서 모든 알파벳으로 시작하는 것에 대해 시도 하고, 각 

 - 전체 문제: N 길이의 두 문자열에 대해 두 문자열의 최장 공통 부분 수열 구하기!


*/


// LCS를 구하기 위한 배열
int dp[1001][1001] = { {0, } };

// 값을 입력받을 문자열
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