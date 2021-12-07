#include<iostream>
using namespace std;

// dp[i] i번째 상자까지 고려했을 때 최대로 겹칠 수 있는 상자의 개수
int dp[1000] = { 0, };
// 각 상자의 크기
int A[1000] = { 0, };

int n; // 수열의 길이

int solution() {
    int answer = 0;
    dp[0] = 1;
    for (int i = 0;i < n;i++) {
        dp[i] = 1;
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(dp[i], answer);
    }
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}

	cout << solution();
}
