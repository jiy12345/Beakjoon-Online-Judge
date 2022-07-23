#include<iostream>
using namespace std;

#define MAX 101

long long dp[MAX];

int N;

long long solution() {
	// 6번까지는 그냥 입력이 최대값!
	for (int i = 1; i <= 6; i++)
		dp[i] = i;

	for (int i = 7; i <= N; i++)
		for (int j = 3; i - j > 0; j++) 
			dp[i] = max(dp[i], (j - 1) * dp[i - j]);

	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution();
}
