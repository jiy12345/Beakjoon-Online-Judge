#include<iostream>
using namespace std;

int n;

int sequence[100000];
int dp[100000];

int solution() {
	
	dp[0] = sequence[0]; // 가장 첫 위치는 자기 자신밖에 없으므로

	int answer = dp[0];

	for (int i = 1; i < n; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = sequence[i];
		}
		else {
			dp[i] = sequence[i] + dp[i - 1];
		}
		answer = max(dp[i], answer);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	cout << solution();
}
