#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

// 각 위치의 사탕의 개수
int num_of_candy[1001][1001];

// 각 위치까지의 사탕 개수의 최대값 구하기
int dp[1001][1001];


// 미로의 세로 길이와 가로 길이
int N, M;

int solution(int n, int m) {
	// 경계를 벗어났을 경우 0 리턴
	if (n == 0 || m == 0) {
		return 0;
	}
	
	// 처음에는 0으로 초기화 했다가 문제가 생김!
	// 초기화하는 값은 항상 나올 수 없는 값이어야한다는 것을 명심하자!
	if (dp[n][m] != -1) {
		return dp[n][m];
	}
	else {

		// 현 위치의 사탕 값과 이전에 올 수 있는 위치들의 값들 중 최대값 더하기
		dp[n][m] = num_of_candy[n][m] + max({ solution(n - 1,m), solution(n, m - 1), solution(n - 1, m - 1)});
		return dp[n][m];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  	// 배열의 모든 값 -1로 초기화
	memset(dp, -1, sizeof(int) * 1001 * 1001);

	// 초기값 입력
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> num_of_candy[i][j];
		}
	}

	cout << solution(N, M);
}
