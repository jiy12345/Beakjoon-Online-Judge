#include<iostream>
#include<numeric>
using namespace std;

/*
1. 문제 분석
- 변수
N: 숫자의 개수

- 변수 제한 사항
N: 3~100
주어지는 숫자 0~9

- 문제 상황
상근이가 0부터 20까지 안다고 할 때, +, - 를 넣어 만든 수식의 중간 결과를 포함한 모든 결과가 상근이가 아는 수일 경우의 수를 구하여라

합의 수가 0부터 20까지로 한정적인 범위 내에 표현이 가능하므로,

2. 풀이 계획
 dp[i] = i+1번째 수까지 연산했을 때의 경우의 수

3. 계획 검증
*/

int num[100];

long long dp[100][21];
int N;


long long solution() {

	// 가장 첫 수를 포함!
	dp[0][num[0]] = 1;

	for (int i = 1;i < N - 1;i++) {
		for (int j = 0;j <= 20;j++) {
			if (j + num[i] <= 20) {
				dp[i][j + num[i]] += dp[i - 1][j];
			}
			if (0 <= j - num[i]) {
				dp[i][j - num[i]] += dp[i - 1][j];
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j <= 20;j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return dp[N - 2][num[N - 1]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> num[i];
	}

	cout<< solution();
}