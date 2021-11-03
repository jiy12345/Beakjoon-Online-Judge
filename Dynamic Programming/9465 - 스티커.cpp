#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sticker[2][100000] = { {0, } };

// dp[i][j]: j열의 i(0:위, 1:아래)행 스티커를 선택했을 때의 최대값
int dp[2][100000] = { {0, } };

// 테스트 케이스의 개수
int T = 0;

// 열의 길이
int n;

int solution() {
	// 초기값 설정해주기
	dp[0][0] = sticker[0][0];
	dp[1][0] = sticker[1][0];
	dp[0][1] = sticker[0][1] + sticker[1][0];
	dp[1][1] = sticker[1][1] + sticker[0][0];

	for (int i = 2;i < n;i++) {
		// 현 위치에서 위쪽 스티커를 선택한 경우
		dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		// 현 위치에서 아래쪽 스티커를 선택한 경우
		dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	return max(dp[0][n - 1], dp[1][n - 1]);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0;i < T;i++) {
		cin >> n;
		for (int j = 0;j < 2;j++) {
			for (int k = 0;k < n;k++) {
				cin >> sticker[j][k];
			}
		}
		cout << solution() << '\n';
	}
}
