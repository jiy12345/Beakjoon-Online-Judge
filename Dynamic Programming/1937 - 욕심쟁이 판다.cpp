#include<iostream>
#include<cstring>
using namespace std;


/*
1. 문제 분석
- 변수
n: 대나무 숲의 가로, 세로 길이

 - 변수 제한 사항
n: 1 ~ 500

각 지역의 대나무의 양: 1 ~ 1,000,000

- 문제 상황
 판다가 다음과 같이 움직인다고 하자.

- 한 지역에서 대나무를 먹는다.
- 지역의 대나무를 다 먹으면 상, 하, 좌, 우중 한곳으로 이동한다.
- 현재 지역보다 대나무가 많은 지역으로만 이동한다.

 대나무 숲의 상태가 주어졌다고 할 때, 판다가 이동할 수 있는 칸의 최대값을 구하여라

2. 풀이 계획
 모든 위치에 대해 검색하되, 그 위치가 최소값이나 최대값이라는 보장이 없으므로

 그 위치로부터 작아지는 방향으로의 이동과, 커지는 방향으로의 이동의 합을 더하자!
  => 이렇게 하면 시간초과가 발생한다.
 
 사실 처음 생각한 방향으로 진행하면 중복된 연산을 진행해야 하는 부분이 너무 많다.

 그렇다면 어떻게 중복 연산되는 부분을 줄일 수 있을까?

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int n;
int bambooForest[500][500];
int maxDist[500][500];

bool isInRange(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

int dfs(int cur_i, int cur_j) {
	if (maxDist[cur_i][cur_j] != 0) return maxDist[cur_i][cur_j];
	// 현재 칸도 포함되어야 하므로
	maxDist[cur_i][cur_j] = 1;

	for (int i = 0; i < 4; i++) {
		int next_i = cur_i + di[i];
		int next_j = cur_j + dj[i];

		// 숲 범위 밖일 경우 탐색을 진행하지 않음
		if (!isInRange(next_i, next_j)) continue;


		if (bambooForest[cur_i][cur_j] < bambooForest[next_i][next_j]) {
			maxDist[cur_i][cur_j] = max(maxDist[cur_i][cur_j], dfs(next_i, next_j) + 1);
		}
	}

	return maxDist[cur_i][cur_j];
}

int solution() {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			answer = max(answer, dfs(i, j));
		} 
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bambooForest[i][j];
		}
	}

	cout << solution();

	return 0;
}