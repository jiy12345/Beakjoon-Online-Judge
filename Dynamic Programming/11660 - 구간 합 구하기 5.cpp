#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석

- 변수
N: 표의 크기
M: 합을 구해야 하는 횟수

- 변수 제한 사항
N: 1~1,024
M: 1~100,000



- 문제 상황
 표에 있는 수들과 

M개의 네 개의 정수모음 (x1, y1, x2, y2) 가 주어질 때
(x1, y1)부터 (x2, y2)까지의 합을 구해 출력한다. (x1 ≤ x2, y1 ≤ y2)

2. 풀이 계획


일단 각 위치의 부분합은 다음과 같이 나타낼 수 있다.

dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

위와 같은 식이 나오는 이유는 dp[i-1][j] + dp[i][j-1]를 더하면 이중으로 더해지는 부분이 있기 때문에 그 부분을 빼줘야 하기 때문이다.


이렇게 구하고 나면, 다음과 같은 식을 통해 구간의 합을 구할 수 있다.

(x1, y1)부터 (x2, y2)까지의 합 = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];





3. 계획 검증


*/

int N, M;


int table[1025][1025];
int dp[1025][1025];

void solution() {
	int x1, y1, x2, y2;

	for (int i = 0;i < M;i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout<< dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	// 입력 받으며 각 위치까지의 합 구하기
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> table[i][j];
			dp[i][j] = table[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	solution();

	return 0;
}