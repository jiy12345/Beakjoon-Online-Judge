#include<iostream>
#include<algorithm>
using namespace std;

int triangle[122250];

int dp[122250];

int n;

int solution() {
	// 초기값 설정
	dp[0] = triangle[0];

	// 각 층별 반복
	// layer: 삼각형의 각 층. 이 변수가 n이라면 (n+1)층을 나타냄!
	// location: 전체 배열에서의 위치를 나타내기 위한 변수
	for (int layer = 1; layer < n; layer++) {
		for (int location = layer * (layer + 1) / 2; location < (layer + 1) * (layer + 2) / 2; location++) {
			// 각 줄의 첫 위치일 때
			if (location == layer * (layer + 1) / 2) {
				// 바로 윗줄의 첫 위치값이 그대로 더해짐
				dp[location] = dp[layer * (layer - 1) / 2] + triangle[location];
			} 
			// 각 줄의 가장 마지막 위치일 때
			else if(location == (layer + 1) * (layer + 2) / 2 - 1){
				// 바로 윗줄의 마지막 위치값이 그대로 더해짐
				dp[location] = dp[layer * (layer + 1) / 2 - 1] + triangle[location];
			}
			// 나머지 중간 위치일 때
			else { 
				// 해당 위치에 올 수 있는 양쪽 경로에 대해 계산
				dp[location] = max(dp[location - layer], dp[location - (layer + 1)]) + triangle[location];
			}
		}
	}

	// 마지막 줄의 시작점부터 끝 점까지 저장된 값들 중 가장 큰 값 계산하기!
	return *max_element(dp + (n * (n - 1) / 2), dp + (n * (n + 1) / 2));
}


int main() {
	cin >> n;

	for (int i = 0; i < n * (n + 1) / 2; i++) {
		cin >> triangle[i];
	}

	cout << solution();
}
