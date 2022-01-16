#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int Map[50][50];
vector<pair<int, int>> chickenPlace;		// 현재 존재한 모든 치킨집의 좌표
vector<pair<int, int>> selectedChickenPlace;	// 현재 선택된 모든 치킨집의 좌표
int N, M;

// 두 점 사이의 맨하탄 거리 구하는 함수
int manhattanDistance(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

// 각 집에서의 치킨 거리를 계산하는 함수
int chickenDistance(pair<int, int> Housing) {
	int minDistance = 200;
	
	for (int i = 0; i < selectedChickenPlace.size(); i++) {
		minDistance = min(minDistance, manhattanDistance(Housing, selectedChickenPlace[i]));
	}

	return minDistance;
}

// 조합으로 모든 치킨집 중 M개의 치킨집을 뽑아 치킨 거리를 계산하는 함수
// curStartIndex:탐색을 시작해야 하는 위치
int solution(int curStartIndex) {
	int minDistance = 100000000;

	if (selectedChickenPlace.size() == M) {
		int sumOfChickenDistance = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j] == 1) {
					sumOfChickenDistance +=chickenDistance(make_pair(i, j));
				}
			}
		}

		return sumOfChickenDistance;
	}

	for (int i = curStartIndex; i < chickenPlace.size(); i++) {
		selectedChickenPlace.push_back(chickenPlace[i]);
		minDistance = min(minDistance, solution(i + 1));
		selectedChickenPlace.pop_back();
	}

	return minDistance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];

			if (Map[i][j] == 2) {
				chickenPlace.push_back(make_pair(i, j));
			}
		}
	}

	cout << solution(0);
}
