#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//      아래, 위, 오른쪽, 왼쪽
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

// 외부 경계를 0으로 하여 외부는 고려하지 않도록 하기!
int map[502][502];

// dp[i][j]: i, j까지 갈 수 있는 경로의 수
int dp[502][502];

int M, N;

int solution(int m, int n) {
    // 이미 계산된 값이 있다면 사용
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    // 4방향으로 진행
    for(int i = 0;i < 4;i++) {
        // 더 높은 위치에 대해서만 고려하기
        if (map[m][n] < map[m + dx[i]][n + dy[i]]) {
            dp[m][n] += solution(m + dx[i], n + dy[i]);
        }
    }

    // -1로 초기화 되어있으므로 1더해주기
    dp[m][n]++;

    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> M >> N;

    // 0도 저장될 수 있으므로 -1로 초기화
    memset(dp, -1, 502 * 502 * sizeof(int));

    for (int i = 1;i <= M;i++) {
        for (int j = 1;j <= N;j++) {
            cin >> map[i][j];
        }
    }

    // 가장 첫 위치는 무조건 갈 수 있으므로 1로 초기화
    dp[1][1] = 1;

    cout << solution(M, N);
}
