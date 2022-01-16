#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int Map[50][50];
vector<pair<int, int>> chickenPlace;
vector<pair<int, int>> selectedChickenPlace;
int N, M;

// 두 점 사이의 맨하탄 거리 구하기
int manhattanDistance(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

// 
int chickenDistance(pair<int, int> Housing) {
	int minDistance = 200;
	
	for (int i = 0; i < selectedChickenPlace.size(); i++) {
		minDistance = min(minDistance, manhattanDistance(Housing, selectedChickenPlace[i]));
	}

	return minDistance;
}

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
