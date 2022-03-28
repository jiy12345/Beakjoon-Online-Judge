#include<iostream>
#include<vector>
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

// 값을 입력받을 배열
int A[1000000];
int index[1000000];

int N; // 수열의 길이

void solution() {

    vector<int> LIS;

    LIS.push_back(A[0]);
    index[0] = 1;

    for (int i = 1; i < N; i++) {
        // 현 위치의 수가 현재 기록중인 LIS의 모든 수보다 큰 수일 경우
        if (LIS.back() < A[i]) {
            LIS.push_back(A[i]);
            index[i] = LIS.size();
        }
        else { // 현 위치의 수보다 더 큰 수가 LIS에 있을 경우
            auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *it = A[i];
            index[i] = it - LIS.begin() + 1;
        }
    }

    cout << LIS.size() << '\n';

    vector<int> answer(LIS.size());
    int cnt = LIS.size();
    for (int i = N - 1; i >= 0; i--) {
        if (index[i] == cnt) {
            answer[cnt - 1] = A[i];
            cnt--;
        }
    }

    for (int i = 0; i < LIS.size(); i++) {
        cout << answer[i] << " ";
    }
}

class E {
public:
    int e[30];

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //cin >> N;

    //for (int i = 0; i < N; i++) {
    //    cin >> A[i];
    //}

    E e;
    
    e.e[3] = 10;

    E f;
    f = e;

    cout << f.e[3];

    //solution();
}