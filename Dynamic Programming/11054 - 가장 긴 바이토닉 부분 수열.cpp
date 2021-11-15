#include<iostream>
#include<algorithm>
using namespace std;

int dp_increase[1001];
int dp_decrease[1001];
int dp_bitonic[1001];

int A[1001];

int N;

int solution() {
	// 초기값 설정
	dp_increase[1] = 1;
	dp_decrease[N] = 1;

	// 증가 수열 구하기
	for (int i = 2;i <= N;i++) {
		// 앞쪽부터 현재 수까지의 가장 긴 증가 부분 수열 구하기
		for (int j = 1;j < i;j++) {
			// 증가 수열의 조건을 충족할 때만 고려하기
			if (A[i] > A[j]) {
				// 이전 위치까지의 증가 수열 중 최장 길이 구하기
				dp_increase[i] = max(dp_increase[i], dp_increase[j]);
			}
		}
		// 현재 값은 항상 포함되어야 하므로 1 더해주기
		dp_increase[i]++;
	}

	// 감소 수열 구하기
	for (int i = N - 1;i >= 1;i--) {
		// 뒤쪽부터 현재 수까지의 가장 긴 감소 부분 수열 구하기
		for (int j = i + 1;j <= N;j++) {
			// 감소 수열의 조건을 충족할 때만 고려하기
			if (A[i] > A[j]) {
				// 이전 위치까지의 증가 수열 중 최장 길이 구하기
				dp_decrease[i] = max(dp_decrease[i], dp_decrease[j]);
			}
		}
		// 현재 값은 항상 포함되어야 하므로 1 더해주기
		dp_decrease[i]++;
	}

	// 바이토닉 수열 구하기
	for (int i = 1;i <= N;i++) {
		// 현 위치 수를 중심으로 하는 바이토닉 수열의 길이 계산
		dp_bitonic[i] = dp_increase[i] + dp_decrease[i] - 1;
	}

	return *max_element(dp_bitonic, dp_bitonic + N + 1);
}

int main() {
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> A[i];
	}

	cout << solution();
}
