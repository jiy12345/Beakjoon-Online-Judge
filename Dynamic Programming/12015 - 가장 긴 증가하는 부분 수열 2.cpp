#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수열 A의 크기


- 변수 제한 사항
N: 1~1,000
수열 A를 이루고 있는 수의 크기: 1~1,000

- 문제 상황
수열 A의 가장 긴 증가하는 부분수열의 길이를 출력하라

2. 풀이 계획
각 위치를 선택하느냐, 선택하지 않느냐에 따라 수열이 달라질 수 있다!
그리고 각 위치까지의 최장 증가 부분 수열의 크기는 항상 같으므로, 현 위치보다 다음 수가 작은 수만 아니라면 문제없이 적용이 가능하다!

따라서 자세한 계획은 다음과 같다.
1. 배열에 수열을 입력받는다.
2. BFS로 N번째 항 부터 선택을 하느냐 하지 않느냐에 따른 모든 위치에서의 최대값을 계산하고,
 => 현 위치를 선택했을 때: 현 위치의 수를 넘겨주며 이전 수에 대한 재귀적 호출을 진행한다.
                           => 저장된 값이 있을 경우 현 위치의 값을 반환한다.
 => 현 위치를 선택하지 않았을 때: 더 앞의 수로부터 전달받은 수를 넘겨주며,
                           => 저장된 값을 쓸 필요 없이 재귀적 호출을 진행한다.
*/


int dp[1000] = { 0, };

vector<int> LIS[1000];

// 값을 입력받을 배열
int A[1000] = { 0, };

int N; // 수열의 길이

// 가장 긴 수열을 저장하고 있는 인덱스
int cur_max_index;
int cur_max_size;

int solution() {
    int answer = 0;
    dp[0] = 1;
    LIS[0].push_back(A[0]);

    if (N == 1) {
        return 1;
    }

    for (int i = 1;i < N;i++) {
        dp[i] = 1;
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i]) {
                if (dp[i] < dp[j] + 1) {
                    // 수열의 길이 저장
                    dp[i] = dp[j] + 1;

                    LIS[i].clear();
                    // 이전에 구해진 수열을 이용하여 구하기
                    for (int k = 0;k < LIS[j].size();k++) {
                        LIS[i].push_back(LIS[j][k]);
                    }


                    if (LIS[i].size() > cur_max_size) {
                        cur_max_size = LIS[i].size();
                        cur_max_index = i;
                    }
                }
            }
        }
        LIS[i].push_back(A[i]);
        answer = max(dp[i], answer);
    }
    return answer;
}

int main() {
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    cout << solution() << '\n';

    for (int i = 0;i < LIS[cur_max_index].size();i++) {
        cout << LIS[cur_max_index][i] << " ";
    }
}