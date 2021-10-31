#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Pi
int P[1000] = { 0, };

// 각 카드의 개수를 구하는데 필요한 가격중 최대값
int dp[1000] = { 0, };

int N; // 구매하려는 카드의 개수

int solution() {
	// 1장은 그대로 1장 사는 것이 최대값
	dp[0] = P[0];

	for (int i = 1;i < N;i++) {
		// 각 위치에서 비교해야할 값들을 모두 저장할 벡터
		vector<int>cur_comparison_values;
		// 각 위치에 저장된 최대값들과 해당 개수로부터 더 사야 하는 카드 개수의 팩을 샀을 때의 합을 계산
		for (int j = 0;j < i;j++) {
			cur_comparison_values.push_back(dp[j] + P[i - j - 1]);
		}
		// 현재 카드의 개수를 가진 팩을 그대로 사는 것도 고려
		cur_comparison_values.push_back(P[i]);
		
		// 계산된 값들 중 최대값 구하기
		dp[i] = *max_element(cur_comparison_values.begin(), cur_comparison_values.end());
	}

	// 최종적인 값 리턴
	return dp[N - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> P[i];
	}

	cout << solution();
}

