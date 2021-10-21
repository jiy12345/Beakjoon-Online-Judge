#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 각 위치에서 특정 색을 선택했을 때의 최소값 저장할 배열
int min_nums[1000][3] = { {0, } };
// 값을 입력받을 배열
int RGB_cost[1000][3] = { {0, } };

int N; // 집의 수

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
		// 현 위치의 값과 이전 위치의 최소값들 중 더 작은 것과의 합을 현재의 최소값으로 저장
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
		// 0부터 시작하는 인덱스이므로 N-1이 마지막 위치인 N 위치!
		previous_min_num.push_back(solution(N - 1, i));
	}

	// 세가지 색을 선택했을 경우 중 가장 최소값을 도출한 색 선택하여 출력
	cout<< *min_element(previous_min_num.begin(), previous_min_num.end());
}
