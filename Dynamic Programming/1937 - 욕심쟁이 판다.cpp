#include<iostream>
#include<cstring>
using namespace std;

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
