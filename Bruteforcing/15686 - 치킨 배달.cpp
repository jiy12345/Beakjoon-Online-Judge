#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
1. 문제 분석
- 변수
N: 도시의 가로, 세로 길이
M: 치킨집의 최대 개수

- 변수 제한 사항
N: 2~50
M: 1~13

집의 개수: 1~2N
치킨집의 개수: M~13

- 문제 상황
 치킨 거리를 집과 치킨집의 거리로 다음과 같이 구한다고 하고,

 |r1-r2| + |c1-c2|

 도시의 치킨 거리를 모든 집의 치킨거리의 합이라 한다.

 또한, 현재 주어진 치킨집 중 M개의 치킨집만 고르고 나머지는 폐업해야 한다고 한다.

 이 때 도시의 치킨거리의 최솟값을 출력하라.

2. 풀이 계획
 일단 순서에 상관없이 M개의 치킨집을 뽑아야 하는 조합 문제이므로, 재귀로 구현하면 될 듯 하다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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