#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
l: 막대의 길이
n: 개미의 수

- 변수 제한 사항
1 ≤ n ≤ 100,000
1 ≤ l ≤ 1,000,000
개미의 위치는 정수
0 ≤ 개미의 위치 ≤ l


- 문제 상황
각 테스트 케이스에 대해서 개미가 모두 땅으로 떨어지는 가능한 시간중 가장 빠른 시간, 가장 늦은 시간을 출력한다.
2. 풀이 계획

문제가 되는 점: 조건을 고려한 것을 한번에 어떻게 나타낼 것이냐?

각 위치에서의 합은 원래는

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 이어야 하나, 각 조건에 따라 또 나뉘어져야 한다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int t;
int n, l;

void solution() {
    int maxTime = 0;
    int minTime = 0;

    int location;
    for (int i = 0; i < n; i++) {
        cin >> location;

        minTime = max(minTime, min(location, l - location));
        maxTime = max(maxTime, max(location, l - location));
    }

    cout << minTime << " " << maxTime << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> l >> n;
        solution();
    }
}