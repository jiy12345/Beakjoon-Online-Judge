#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수열 A의 크기

- 변수 제한 사항
N:1~1,000,000

수열을 이루고 있는 수: 1 ~ 1,000,000

- 문제 상황
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력

2. 풀이 계획

문제가 되는 점: 조건을 고려한 것을 한번에 어떻게 나타낼 것이냐?

각 위치에서의 합은 원래는

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 이어야 하나, 각 조건에 따라 또 나뉘어져야 한다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define MAX 300000

int N, K;
int height[MAX];

int solution() {
    int answer = 0;

    vector<int> diff(N - 1);
    for (int i = 0; i < N - 1; i++)
        diff[i] = height[i + 1] - height[i];

    sort(diff.begin(), diff.end(), greater<int>());

    for (int i = K - 1; i < diff.size(); i++)
        answer += diff[i];

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> height[i];

    cout << solution() << endl;

    return 0;
}