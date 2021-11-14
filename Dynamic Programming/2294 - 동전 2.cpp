#include<iostream>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
 n: 동전의 가지 수 
 k: 만드려는 금액

- 변수 제한 사항
 n: 1~100
 k: 1~10,000
 각 동전의 가치: 1~100,000

- 문제 상황
첫째 줄에 n, k가 주어질 때,사용한 동전의 최소 개수를 출력한다.
불가능한 경우에는 -1을 출력한다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

2. 풀이 계획
 - 전체 문제: M, N 위치까지 갈 수 있는 경로의 수
 - 부분 문제: m, n 까지 갈 수 있는 경로의 수

 앞서서 어떤 위치에서 올지 모르므로, 탑다운 방식으로 구현해야할듯 하다!

M, N 위치에서 시작하여, 각 위치별로 해당 위치보다 높은 위치에 대해서만 구하면 될 듯 하다!

4방향으로 이동하므로 무한정 돌게 되는 상황을 주의해야 하지만, 오르막으로만 이동하므로 큰 문제는 없을 듯 하다!

각 위치별로 각 위치보다 높은 주변 4방향의 위치까지의 경로의 수를 더하면 될 듯 하다!

3. 계획 검증
*/


// 외부 경계를 0으로 하여 외부는 고려하지 않도록 하기!
int coin[100];

// dp[i]: i 금액을 만들 수 있는 동전의 최소 개수
int dp[10001];

int n, k;

int solution() {
    for (int i = 0;i < n;i++) {
        // 각 동전의 가치가 목표 금액보다 작거나 같을때만 진행
        if (coin[i] <= k) {
            // 각 동전에 해당하는 금액은 동전 하나로 만들 수 있음!
            dp[coin[i]] = 1;
            for (int j = coin[i];j <= k;j++) {
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            }
        }
    }

    if (dp[k] > 10000) {
        return -1;
    }
    else {
        return dp[k];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    memset(dp, 10001, sizeof(dp));

    cin >> n >> k;

    for (int i = 0;i < n;i++) {
        cin >> coin[i];
    }

    cout << solution();
}