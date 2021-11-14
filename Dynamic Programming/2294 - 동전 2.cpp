#include<iostream>
#include<cstring>
using namespace std;

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
