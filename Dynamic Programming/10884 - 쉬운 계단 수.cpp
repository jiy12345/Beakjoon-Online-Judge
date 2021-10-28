#include<iostream>
using namespace std;

// 각 위치의 수에 따른 경우의 수
long long dp[10][100] = { {0,}, };

int N; // 계단의 개수

// cur_index: 현 위치의 인덱스 
// cur_num: 현 위치의 수
long long solution(int cur_index, int cur_num) {
	// 기저 사례
	if (cur_index == N - 1) {
		return 1;
	}

	// 이미 저장된 값이 있을 경우 그대로 리턴
	if (dp[cur_num][cur_index] != 0) {
		return dp[cur_num][cur_index];
	}

	// 0일 경우 다음 수는 무조건 1이어야 함
	if (cur_num == 0) {
		dp[cur_num][cur_index] = solution(cur_index + 1, 1) % 1000000000;
		return dp[cur_num][cur_index];
	}
	// 9일 경우 다음 수는 무조건 8이어야 함
	else if (cur_num == 9) {
		dp[cur_num][cur_index] = solution(cur_index + 1, 8) % 1000000000;
		return dp[cur_num][cur_index];
	}
	// 나머지 경우 위 아래 모두로 진행 가능
	else {
		dp[cur_num][cur_index] = ((solution(cur_index + 1, cur_num + 1)% 1000000000) + (solution(cur_index + 1, cur_num - 1)%1000000000))% 1000000000;
		return dp[cur_num][cur_index];
	}
}

int main() {
	cin >> N;

	long long answer = 0;

	// 각 시작 위치별로 모든 수 구해주기
	for (int i = 1;i < 10;i++) {
		answer += (solution(0, i) % 1000000000);
	}

	cout << answer%1000000000;
}

