#include<iostream>
using namespace std;

int T, N, M;

int coin[20];

int solution() {
	int dp[10001] = { 0, };

	// 딱 맞는 금액을 만들었다는 의미의 1
	dp[0] = 1;
	
	for (int i = 0;i < N;i++) {
		for (int j = coin[i];j <= M;j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	return dp[M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	for (int i = 0;i < T;i++) {
		cin >> N;

		for (int j = 0;j < N;j++) {
			cin >> coin[j];
		}

		cin >> M;

		cout << solution() << '\n';
	}
}
