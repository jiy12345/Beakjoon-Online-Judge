#include<iostream>
using namespace std;

int N, M, K;
int input[302][302];
int dp[302][302];

void setArray() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dp[i][j] = input[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
}

void solution() {
    setArray();

    for (int k = 0; k < K; k++) {
        int i, j, x, y;

        cin >> i >> j >> x >> y;

        cout << dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> input[i][j];

    cin >> K;

    solution();
}