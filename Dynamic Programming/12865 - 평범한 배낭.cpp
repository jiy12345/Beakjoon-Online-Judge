#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 물건의 개수
 K: 최대 버틸 수 있는 무게
 W[i]: i번째 물건의 무게
 V[i]: i번째 물건의 가치
- 변수 제한 사항
 N: 1~100
 K: 1~100,000
 W: 1~100,000
 V: 0~100,000
- 문제 상황
 N과 K가 주어지고, 각 물건의 W와 V가 주어질 때, 배낭에 넣을 수 있는 물건들의 가치합의 최대값을 출력한다!
2. 풀이 계획
 - 전체 문제: K 무게로 구성할 수 있는 물건들의 가치합의 최대값.
 - 부분 문제: k(1 <= k < K) 무게로 구성할 수 있는 물건들의 가치합의 최대값.
그런데 이 문제에서 문제가 되는 것은 각 물건이 한번 포함되고 나면 다시 포함될 수 없다는 것이다!
 한번 사용된 물건은 어떻게 표시할까?
=> 재귀로 구현해야 할 것 같다!
재귀를 이용하여도 같은 수를 다른 시점에 참조하여 바꿀 수 있는 것은 어쩔 수없나? => 그러면 다이나믹 프로그래밍의 의미가 없어짐
각 무게별로 최대값을 계산하는 것이 의미가 있을까?
3. 계획 검증
*/

// dp[i][j]: i번째 물건까지 탐색했고, 탐색하여 담은 물건들의 무게의 합이 j
int dp[101][100001];

int V[101]; // 각 물건의 가치
int W[101]; // 각 물건의 무게

int N, K;

int solution() {
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j >= W[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][K];
}


int main() {
    cin >> N >> K;
    
    for (int i = 1;i <= N;i++) {
        cin >> W[i] >> V[i];
    }

    cout << solution();
}
