#include<iostream>
#include<algorithm>
using namespace std;

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
                // 현재항과 j까지 계산된 값 중 최대값의 합이 dp[i]에 저장!
                dp[i] = max(dp[i], A[i] + dp[j]);
            }
        }
    }
    // 계산된 값 중 최대값 반환!
    return *max_element(dp, dp + N);
}

int main() {
    cin >> N;
    
    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    cout << solution();
}
