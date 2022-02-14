#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
n: 수열에 속한 정수의 개수

- 변수 제한 사항
n:1~100,000
수열에 속한 수: -1,000~1,000

- 문제 상황
 n개의 수를 가진 수열이 주어졌을 때, 연속된 몇개의 수를 선택하여 구할 수 있는 합 중 가장 큰 합을 구하여라.
 이 때, 연속된 수 중 한 수는 제외될 수 있다.

2. 풀이 계획
 제거 안한 상태의 합과 제거 한 상태의 합을 따로 저장하는게 좋을 듯 하다!

 제거 안한 상태의 최대값


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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