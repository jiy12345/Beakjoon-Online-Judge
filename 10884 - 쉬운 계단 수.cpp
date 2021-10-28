#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 계단 수의 길이

- 변수 제한 사항
N: 1~100

- 문제 상황
 인접한 모든 자리의 차이가 1인 수를 계단수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하여라

2. 풀이 계획
각 시작 수(1~9)별로 계단 수의 경우의 수를 구하면 될 듯 하다!

구해야 하는 값
모든 계단 수의 경우의 수

부분 문제
각 시작위치에 따른 계단 수의 경우의 값

부분 문제의 부분 문제
각 위치에서 수에 따른 경우의 수



*/

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

	for (int i = 1;i < 10;i++) {
		answer += (solution(0, i) % 1000000000);
	}

	cout << answer%1000000000;
}

