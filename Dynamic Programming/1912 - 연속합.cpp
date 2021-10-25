#include<iostream>
using namespace std;

int n;

// 수열이 저장될 배열
int sequence[100000];
// 각 항까지의 연속합의 최대값이 저장될 배열
int dp[100000]; 

int solution() {
	
	dp[0] = sequence[0]; // 가장 첫 위치는 자기 자신밖에 없으므로

	int answer = dp[0];

	// 점화식
	for (int i = 1; i < n; i++) {
		// 이전항까지의 연속합의 최대값이 음수일 경우
		if (dp[i - 1] < 0) {
			// 현 위치의 항이 가지고 잇는 값만 더함
			dp[i] = sequence[i];
		}
		// 이전항까지의 연속합의 최대값이 양수일 경우
		else {
			// 현 위치의 항이 가지고 있는 값과 이전항까지의 연속합의 최대값을 더함 
			dp[i] = sequence[i] + dp[i - 1];
		}
		// 현재 저장된 연속합의 최대값과 비교하여 더 큰값으로 저장
		answer = max(dp[i], answer);
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	cout << solution();
}
