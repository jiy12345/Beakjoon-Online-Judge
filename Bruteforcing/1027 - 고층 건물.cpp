#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

/*
1. 문제 분석

- 변수
N: 빌딩의 개수

- 변수 제한 사항
1 <= N <= 50
1 <= 각 빌딩의 높이 <= 1,000,000,000

 - 문제 상황
 i번째 빌딩 (1부터 시작)은 (i,0)부터 (i,높이)의 선분으로 나타낼 때,
 빌딩 A에서 빌딩 B를 볼 수 있으려면 두 지붕을 잇는 선분이 A, B를 제외한 다른 고층 빌딩을 지나거나 접하지 않아야 한다!
 가장 많은 고층 빌딩이 보이는 빌딩에서 보이는 빌딩의 수를 출력하라!

2. 풀이 계획
 두 좌표간의 직선의 방정식을 구한뒤, 
 직선의 방정식에 각 건물의 위치를 대입해서 나온 값과 실제 값을 비교하여
 실제 값이 더 큰 건물이 하나라도 있을 경우 두 건물간에 보이지 않는 것이라고 판단하면 될 듯 하다.

 N x N 이차원 배열을 만든 후, 서로 보이는 위치를 1로, 보이지 않는 위치를 0으로 표현하여 값들을 구한뒤,
 마지막에 모두 합해주면 될듯 하다.

1. N x N 이차원 배열을 생성한다.
2. 0부터 N까지, 1부터 N까지, 2부터 N까지, ... N부터 N까지 반복을 진행하며 각각의 두 위치에서 서로가 보이는지 판단하고,
 그 값을 이차원 배열에 저장한다.

3. 계획 검증


*/

int solution(int N) {
	int i, j, k;
	vector<int> building_h;
	
	int** able_to_see = new int* [N];

	for (int i = 0; i < N; i++) {
		able_to_see[i] = new int[N](0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << able_to_see[i][j] << endl;
		}
	}
	
	for (i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		building_h.push_back(temp);
	}



	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) { // i와 j 건물 비교
			// 두 지점 사이의 직선의 방정식 구하기
			int a = (building_h[j] - building_h[i]) / (j - i); // 기울기
			int b = -(building_h[j] - building_h[i]) * (i + 1) / (j - i) + building_h[i]; // y절편

			for (k = i + 1; k < j; k++) { // 각 위치의 좌표를 직선의 방정식에 대입한 값과 실제 건물 높이 비교

			}
			if (k == j) { // 모든 건물에 대해 무사히 통과하면
				
			}
		}
	}

	return 0;
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}
