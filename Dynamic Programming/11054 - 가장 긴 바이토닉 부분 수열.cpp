#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수열의 길이
Ai: 수열의 i번째 수

- 변수 제한 사항
N: 1~1,000
Ai: 1~1,000

- 문제 상황
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

2. 풀이 계획

이 문제는 가장 긴 증가 부분 수열문제와 매우 유사하다!

가장 긴 바이토닉 수열을 구하려면 어떻게 해야할까?

일단 각 위치가 제일 높은 수일 때에 대해 모두 고려해줘야 한다.

그 수에 대한 가장 긴 바이토닉 수열은 
그 수 왼쪽부터는 가장 긴 증가 부분 수열이, 그 수 오른쪽부터는 가장 긴 감소 부분수열이 올 것이다!

따라서 왼쪽 끝부터 시작하는 각 수를 포함하는 가장 긴 증가 부분 수열과
오른쪽 끝부터 시작하는 각 수를 포함하는 가장 긴 감소 부분 수열울 구하여

그 두 수열을 더하여 각 위치의 수를 중심으로 하는 가장 긴 바이토닉 수열을 구할 수 있을 듯 하다.
그런데 이 때 기준 수는 증가 수열과 감소 수열에 모두 포함되므로, 계산된 값에서 1을 빼줘야 한다!


*/

int dp_increase[1001];
int dp_decrease[1001];
int dp_bitonic[1001];

int A[1001];

int N;

int solution() {
	// 초기값 설정
	dp_increase[1] = 1;
	dp_decrease[N] = 1;

	// 모든 수에 대해 반복
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

	// 모든 수에 대해 반복
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


	for (int i = 1;i <= N;i++) {
		// 현 위치 수를 중심으로 하는 바이토닉 수열의 길이 계산
		dp_bitonic[i] = dp_increase[i] + dp_decrease[i] - 1;
	}

	return *max_element(dp_bitonic, dp_bitonic + N + 1);
}

int main() {
	// 초기값 입력
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> A[i];
	}

	cout << solution();
}