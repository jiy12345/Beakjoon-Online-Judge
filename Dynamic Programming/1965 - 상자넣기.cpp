#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
S: 보낼 이모티콘의 개수

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

int dp[1000] = { 0, };
// 값을 입력받을 배열
int A[1000] = { 0, };

int n; // 수열의 길이

int solution() {
    int answer = 0;
    dp[0] = 1;
    for (int i = 0;i < n;i++) {
        dp[i] = 1;
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(dp[i], answer);
    }
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}

	cout << solution();
}