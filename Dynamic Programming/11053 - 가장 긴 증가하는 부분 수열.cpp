#include<iostream>
using namespace std;

int dp[1000] = { 0, };
// 값을 입력받을 배열
int A[1000] = { 0, };

int N; // 수열의 길이

int solution() {
    int answer = 0;
    dp[0] = 1;
    for (int i = 0;i < N;i++) {
        // 현재 항은 반드시 포함
        dp[i] = 1;
        // 이전의 값들 모두 고려
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 현재 저장된 최장값과 비교하여 더 큰 값이면 갱신
        answer = max(dp[i], answer);
    }
    return answer;
}

int main() {
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    cout << solution();
}
