#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// dp[i][j]: i를 나타낼 때, 마지막에 j를 사용했을 때의 경우의 수
long long dp[100001][4];

void solution(int maxNum) {
	
	dp[1][1] = 1; // 1
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][1] = 0;
	dp[2][2] = 1; // 2
	dp[2][3] = 0;
	dp[3][1] = 1; // 2 + 1
	dp[3][2] = 1; // 1 + 2
	dp[3][3] = 1; // 3

	for (int i = 4; i <= maxNum;i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	vector<int>input;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		input.push_back(n);
	}

	solution(*max_element(input.begin(), input.end()));

	for (int i = 0; i < T; i++) {
		cout << (dp[input[i]][1] + dp[input[i]][2] + dp[input[i]][3]) % 1000000009 << '\n';
	}

	return 0;
}
