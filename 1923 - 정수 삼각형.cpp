#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 n: 삼각형의 크기

- 변수 제한 사항
 N: 1~500
 삼각형이 가진 수의 범위:0~9,999 

- 문제 상황
 맨 위층부터 시작해서 아래층까지 내려가며, 내려가는 경로는 현 위치로부터 바로 왼쪽 아래나 오른쪽 아래만 선택할 수 있다고 할 때,
 합이 최대가 되는 경로에 있는 수의 합을 출력하라.

2. 풀이 계획
 이번에는 재귀를 사용하지 않고 구성해보자.

 그렇다면 일단 출발점에서 시작해서 갈 수 있는 모든 경로에 대해 고려해야 한다.
 => 어떻게 하면 이게 가능할까?

 반복문을 각 층별로 돌린 후, 각 층별로 이전 층에서 계산한 값을 토대로 계산을 진행한다!
 이때 가장 첫 위치는 이전 층의 가장 첫 위치 값만을 더하도록 하고, 가장 마지막 위치는 가장 마지막 위치의 값만 더하도록 한다!

 따라서 자세한 계획을 짜보면 다음과 같다.

1. 1차원 배열에 전체 삼각형을 입력받는다.
2. 삼각형의 크기만큼 반복문을 돌리며, 각 층의 최대값들을 구한다.
3. 삼각형의 마지막 층에 해당하는 부분에서 가장 큰 값을 찾는다.

3. 계획 검증
500 * 501 / 2 = 122,250

501000
0.501
*/

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