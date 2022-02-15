#include<iostream>
using namespace std;

int n;

// 수열이 저장될 배열
int sequence[100000];
// 각 항을 포함한 연속합의 최대값이 저장될 배열
int dp[100000]; 

int solution() {
	
	dp[0] = sequence[0]; // 가장 첫 위치는 자기 자신밖에 없으므로

	int answer = dp[0];

	// 점화식
	for (int i = 1; i < n; i++) {
        	dp[i] = max(dp[i - 1] + sequence[i], sequence[i]);
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
