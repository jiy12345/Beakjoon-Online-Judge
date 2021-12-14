#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 줄의 수

- 변수 제한 사항
 N: 1~100,000


- 문제 상황
 현 위치에서 좌하단, 하단, 우하단으로만 이동할 수 있다고 할 때,

마지막에 이르렀을 때 얻을 수 있는 최대 점수를 구하여라!

2. 풀이 계획

별로 어려울 것 없이 규칙에 따라 각 위치의 최대, 최소를 따로 저장하면 될 듯 하다!

점화식으로 써보면 아래와 같다.

dp[k][0] = map[k][0] + max(dp[k-1][0], dp[k-1][1])
dp[k][1] = map[k][1] + max(dp[k-1][0], dp[k-1][1], dp[k-1][2])
dp[k][2] = map[k][2] + max(dp[k-1][1], dp[k-1][2])

*/

int N;

int map[100000][3];

void solution() {
	int dp_max[3];
	int dp_min[3];

	// 처음 값은 현 위치의 값이 그대로 저장되어야 하므로
	copy(map[0], map[0] + 3, dp_max);
	copy(map[0], map[0] + 3, dp_min);

	for (int i = 1;i < N;i++) {
		int temp_max[3];
		int temp_min[3];

		temp_max[0] = map[i][0] + max(dp_max[0], dp_max[1]);
		temp_max[1] = map[i][1] + max({ dp_max[0], dp_max[1], dp_max[2] });
		temp_max[2] = map[i][2] + max(dp_max[1], dp_max[2]);

		temp_min[0] = map[i][0] + min(dp_min[0], dp_min[1]);
		temp_min[1] = map[i][1] + min({ dp_min[0], dp_min[1], dp_min[2] });
		temp_min[2] = map[i][2] + min(dp_min[1], dp_min[2]);

		// 계산된 값 복사
		copy(temp_max, temp_max + 3, dp_max);
		copy(temp_min, temp_min + 3, dp_min);
	}

	int max_num = max({ dp_max[0], dp_max[1], dp_max[2] });
	int min_num = min({ dp_min[0], dp_min[1], dp_min[2] });

	cout << max_num << " " << min_num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> map[i][j];
		}
	}

	solution();
}