#include<iostream>
using namespace std;

#define NOT_REMOVED 0
#define REMOVED 1
// 현재 위치의 값을 포함하는 값의 합의 최대값
int dp[100000][2];
int sequence[100000];

int solution(int n) {

	dp[0][NOT_REMOVED] = sequence[0]; // 가장 첫 위치는 자기 자신밖에 없으므로
	dp[0][REMOVED] = sequence[0]; // 가장 첫 위치는 자기 자신밖에 없으므로

	int answer = dp[0][NOT_REMOVED];

	for (int i = 1; i < n; i++) {
		dp[i][NOT_REMOVED] = max(dp[i - 1][NOT_REMOVED] + sequence[i], sequence[i]);
		//                   현재 수를 제거하는 경우  / 현재 수를 제거하지 않는 경우
		dp[i][REMOVED] = max(dp[i - 1][NOT_REMOVED], dp[i - 1][REMOVED] + sequence[i]);
	
		answer = max(answer, max(dp[i][NOT_REMOVED], dp[i][REMOVED]));
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	cout << solution(n);

	return 0;
}
