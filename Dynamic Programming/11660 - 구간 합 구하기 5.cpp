#include<iostream>
using namespace std;

int N, M;

int table[1025][1025];
int dp[1025][1025];

void solution() {
	int x1, y1, x2, y2;

	for (int i = 0;i < M;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout<< dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	// 입력 받으며 각 위치까지의 합 구하기
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> table[i][j];
			dp[i][j] = table[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	solution();

	return 0;
}
