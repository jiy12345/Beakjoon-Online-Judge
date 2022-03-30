#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 집의 개수

- 변수 제한 사항
N: 2 ~ 1,000
집을 칠하는 비용: 1 ~ 1,000

- 문제 상황
 각각의 집을 빨강, 초록, 파랑 중 하나의 색으로 칠하되, 다음의 규칙을 만족하여야 한다고 할 때,

 - 1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
 - N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
 - i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.

 모든 집을 칠하는 비용의 최솟값을 구하여라.

2. 풀이 계획
 문제가 되는점은 가장 끝과 가장 처음이 연결됨으로써, 계산이 달라졌다는 것이다.

 각 연산을 진행할 때 처음에 선택한 색을 알아야 한다.

 어차피 합이므로 연산의 순서는 어떻게 바꾸든 상관이 없을 것이다.

 따라서 첫번째와 N-1번째를 제외하고 => 이게 안되는게 첫번째를 제외하더라도 무엇으로 시작하는지는 알아야 한다.

 그렇다면 역시 고정을 하는 것이 제일 나을수도.


3. 계획 검증

*/


// 각 위치에서 특정 색을 선택했을 때의 최소값 저장할 배열
int min_nums[1000][3];
// 값을 입력받을 배열
int RGB_cost[1000][3];

int N; // 집의 수

int solution() {

	int answer = 1000 * 1000 + 1; // 나올 수 잇는 값 중 최대값

	for (int firstHouseColor = 0; firstHouseColor < 3; firstHouseColor++) // 첫 번째 집의 색깔을 지정하여 반복
	{
		for (int i = 0; i < 3; i++)
		{
			// 첫번째 집의 색을 지정하기 위해 나머지 색이 선택될 수 없도록 나머지 색은 최대값으로
			if (i == firstHouseColor)
				min_nums[0][i] = RGB_cost[0][i]; 
			else
				min_nums[0][i] = 1000 * 1000 + 1;
		}

		// 각 위치까지의 최대값 구하기
		for (int i = 1; i < N; i++)
		{
			min_nums[i][0] = min(min_nums[i - 1][1], min_nums[i - 1][2]) + RGB_cost[i][0];
			min_nums[i][1] = min(min_nums[i - 1][0], min_nums[i - 1][2]) + RGB_cost[i][1];
			min_nums[i][2] = min(min_nums[i - 1][0], min_nums[i - 1][1]) + RGB_cost[i][2];
		}

		for (int lastHouseColor = 0; lastHouseColor < 3; lastHouseColor++)
		{
			if (lastHouseColor == firstHouseColor) continue; // 첫번째 집의 색과 마지막 집의 색이 같으면 안되므로 계산 X
			answer = min(answer, min_nums[N - 1][lastHouseColor]); // 나머지 경우의 최솟값을 구함
		}

	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> RGB_cost[i][0] >> RGB_cost[i][1] >> RGB_cost[i][2];
	}

	cout << solution();
}