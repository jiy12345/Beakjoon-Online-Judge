#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long dp[1000001];

void solution(int maxNum) {
	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1, 2
	dp[3] = 4; // 1 + 1 + 1, 1 + 2, 2 + 1, 3

	for (int i = 4; i <= maxNum; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
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
		cout << dp[input[i]] << '\n';
	}

	return 0;
}
