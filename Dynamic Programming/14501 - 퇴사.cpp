#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// dp[i] i+1일차에 퇴사한다고 했을 때 얻을 수 있는 금액의 최대값 
int dp[15] = { 0, };

// 각 날짜에 잡힌 상담이 끝나는 날짜를 저장할 배열
int T[15] = { 0, };
// 각 날짜에 잡힌 상담으로 버는 금액을 저장할 배열
int P[15] = { 0, };

int N;

int solution() {
	// 첫날 잡힌 상담이 하루만에 마무리 될 수 있을 경우
	if (T[0] == 0) {
		dp[0] = P[0];
	}
	else {
		dp[0] = 0;
	}

	for (int i = 1;i < N;i++) {
		vector<int> cur_max;

		// 이전 날짜까지의 최대값 넣어주기
		cur_max.push_back(dp[i - 1]);

		// 현재 날짜에 잡힌 상담이 현재 날짜에 끝날 때
		if (T[i] == i) {
			// 현재 날짜에 잡힌 상담에서 벌 수 있는 비용을 더함
			cur_max[0] += P[i];
		}

		// 현재 날짜에 끝나도록 되어있는 상담들 고려하기
		for (int j = 0;j < i;j++) {
			// 현재 날짜에 끝나는 상담을 발견할 경우
			if (T[j] == i) {
				// 그 상담이 첫날부터 시작할 경우
				if (j == 0) {
					cur_max.push_back(P[j]);
				}
				else {
					// 그 이전의 최대값과 그 날짜의 상담에서 벌 수 있는 비용또한 비교대상에 넣어줌
					cur_max.push_back(dp[j - 1] + P[j]);
				}
			}
		}
		// 고려해야 하는 값들 중 최대값 구하기!
		dp[i] = *max_element(cur_max.begin(), cur_max.end());
	}

	return dp[N - 1];
}

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> T[i] >> P[i];
		T[i] += (i - 1); // 끝나는 날짜로 저장하기
	}

	cout << solution();
}
