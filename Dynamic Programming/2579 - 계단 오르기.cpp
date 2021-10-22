#include<iostream>
using namespace std;

// 각 위치에 어떤 방식으로 왔느냐에 따라 정해진 최대값
// 0: 한계단 오르기, 1: 두계단 오르기
int max_nums[300][2] = { {0, } };
// 값을 입력받을 배열
int stair_point[300] = { 0, };

int N; // 계단의 개수

// n: 현재 계단 
// one_or_two: 이전 계단에서 올라올 때 어떤 방법을 선택해야 하는지
int solution(int n, int one_or_two) {
	// 이미 계산된 최대값이 있을 경우 그대로 반환
	if (max_nums[n][one_or_two] != 0) {
		return max_nums[n][one_or_two];
	}
	else {
		if (one_or_two == 0) { // 1계단 올라온 경우
			// 반드시 이전 계단에서는 두계단을 올라오는 방법을 선택해야 함
			max_nums[n][0] = solution(n - 1, 1) + stair_point[n];
			return max_nums[n][0];
		}
		else { // 2계단 올라온 경우
			// 이전 계단에서는 한계단 올라오거나 두계단 올라오는 방법중 하나를 선택 가능!
			max_nums[n][1] = max(solution(n - 2, 0), solution(n - 2, 1)) + stair_point[n];
			return max_nums[n][1];
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> stair_point[i];
	}

	// 첫 위치와 두번째 위치의 값 저장
	// 첫 위치는 그대로 첫 위치의 점수
	max_nums[0][0] = stair_point[0]; 
	max_nums[0][1] = stair_point[0];
	// 두번째 위치에서는 방법에 따라 점수가 달라짐
	max_nums[1][0] = stair_point[0] + stair_point[1]; // 첫 계단 거쳐서 두번째 계단을 오므로
	max_nums[1][1] = stair_point[1]; // 두번째 계단만 선택

	// 마지막 위치에 어떻게 왔느냐에 따라 다른 값 저장 후 그 중 더 큰값 선택
	cout << max(solution(N - 1, 0), solution(N - 1, 1));
}
