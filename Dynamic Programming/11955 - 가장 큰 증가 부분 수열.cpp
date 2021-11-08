#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 수열 A의 길이
 K: 최대 버틸 수 있는 무게
 A[i]: 수열의 i번째 수

- 변수 제한 사항
 N: 1~1,000
 A[i]: 1~1,000
 
- 문제 상황
 수열 A와 N이 주어질 때, 합이 가장 큰 증가 부분 수열의 합을 출력한다!

2. 풀이 계획
 - 전체 문제: N 길이의 수열 A에서 가장 합이 큰 증가 부분 수열
 - 부분 문제: k(1 <= k < N) 길이의 수열 A'에서 가장 합이 큰 증가 부분수열

 각 위치에 대해 각 위치의 값은 반드시 선택한다 보고, 이전항들과 비교하여 더 큰지(증가 수열이 가능한지) 체크하고,
 값이 더 크다면 갱신해주는 것으로 진행하면 될듯 하다!

3. 계획 검증
*/

// dp[i]: i번째 수를 포함한 증가 수열 중 합이 가장 큰 증가 부분수열 
int dp[1000];

// 값을 입력받을 배열
int A[1000];

int N;

int solution() {

    // 모든 값에 대해 반복
    for (int i = 0;i < N;i++) {
        // 초기값: 자기자신은 항상 포함해야 함
        dp[i] = A[i];
        for (int j = 0;j < i;j++) {
            // 현재 값이 고려되는 값보다 커서 증가 수열이 가능하고
            if (A[j] < A[i]) {
                // 현재 저장된 값 vs 현재항과 j까지 최대값의 합
                dp[i] = max(dp[i], A[i] + dp[j]);
            }
        }
    }

    return *max_element(dp, dp + N);
}


int main() {
    cin >> N;
    
    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    cout << solution();
}