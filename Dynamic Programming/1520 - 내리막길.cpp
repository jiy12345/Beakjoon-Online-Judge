#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
 M, N: 미로의 세로, 가로 크기

- 변수 제한 사항
M, N: 1~500
각 위치의 높이: 1~10,000

- 문제 상황
 M, N이 주어지고, 각 위치의 높이가 주어질 때, 가능한 경로의 수를 구하라! 

2. 풀이 계획
 - 전체 문제: M, N 위치까지 갈 수 있는 경로의 수
 - 부분 문제: m, n 까지 갈 수 있는 경로의 수 

 앞서서 어떤 위치에서 올지 모르므로, 탑다운 방식으로 구현해야할듯 하다!

M, N 위치에서 시작하여, 각 위치별로 해당 위치보다 높은 위치에 대해서만 구하면 될 듯 하다!

4방향으로 이동하므로 무한정 돌게 되는 상황을 주의해야 하지만, 오르막으로만 이동하므로 큰 문제는 없을 듯 하다!

각 위치별로 각 위치보다 높은 주변 4방향의 위치까지의 경로의 수를 더하면 될 듯 하다!

3. 계획 검증
*/
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;

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