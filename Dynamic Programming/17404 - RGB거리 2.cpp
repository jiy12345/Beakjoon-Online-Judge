#include<iostream>
using namespace std;

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
