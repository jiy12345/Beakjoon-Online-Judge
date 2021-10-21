#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 집의 개수

- 변수 제한 사항
N: 2~1,000

- 문제 상황
 각 위치의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 바로 옆의 집에 같은 색이 칠해지지 않으면서 모든 집을 칠하는 비용의 최소값을 구하라!


2. 풀이 계획

재귀적으로 구현하되 각 위치에서 특정 색을 선택했을 때의 최소값을 저장해놓는다.
특정 위치에서 특정 색을 선택했을 때의 최소 비용은 다음에 어떤 색을 선택하든지 상관 없이

따라서 자세한 계획은 다음과 같다.
1. 3차원 배열에 색을 칠할 때 드는 비용을 입력받는다.
2. BFS로 N번째 집부터 규칙에 따라 각 집을 선택하는 코드를 구현한다.
 => 이 때 해당 위치에서 계산한 그 색을 선택했을 때의 최소값을 저장한다.
*/

// 각 위치에서 특정 색을 선택했을 때의 최소값 저장할 배열
int min_nums[1000][3] = { {0, } };
// 값을 입력받을 배열
int RGB_cost[1000][3] = { {0, } };

int N; // 집의 수

// 00, 01, 10

// n: 어떤 위치의 값인지를 저장할 변수
// RGB: 어떤 색을 선택했는지를 저장할 변수
int solution(int n, int RGB) {
	// 이미 계산된 최소값이 있을 경우 그대로 반환
	if (min_nums[n][RGB] != 0) {
		return min_nums[n][RGB];
	}
	else {
		// 이전에 어떤 색을 선택했느냐에 따라 최소값을 저장할 변수
		vector<int> previous_min_num;
		for (int i = 0;i < 3;i++) {
			// 현재 색과 다를때만 계산하기
			if (i != RGB) {
				previous_min_num.push_back(solution(n - 1, i));
			}
		}
		// 현 위치의 값과 
		min_nums[n][RGB] = RGB_cost[n][RGB] + *min_element(previous_min_num.begin(), previous_min_num.end());
		return min_nums[n][RGB];
	}
}

int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> RGB_cost[i][0] >> RGB_cost[i][1] >> RGB_cost[i][2];
	}

	// 첫 위치의 최소값들은 첫 위치의 비용 그대로이므로 그대로 저장
	for (int i = 0;i < 3;i++) {
		min_nums[0][i] = RGB_cost[0][i];
	}

	// 마지막 집의 색은 3가지 색 모두 가능하므로 모두 시도!
	vector<int> previous_min_num;
	for (int i = 0;i < 3;i++) {
		// 0부터 시작하는 인덱스이므로 N-1이 마지막
		previous_min_num.push_back(solution(N - 1, i));
	}

	cout<< *min_element(previous_min_num.begin(), previous_min_num.end());
}