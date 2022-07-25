#include<iostream>
using namespace std;

int Map[5][5];
int answer = 0; 
bool isVisited[1000000];
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 }; 

inline bool isInRange(int i, int j) {
	return 0 <= i && i < 5 && 0 <= j && j < 5;
}

void DFS(int cur_i, int cur_j, int cur_num, int cnt) {
	if (cnt == 5) {
		if (isVisited[cur_num] == false) {
			isVisited[cur_num] = true;
			answer++;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int next_i = cur_i + di[i];
		int next_j = cur_j + dj[i];

		if (isInRange(next_i, next_j)) {
			DFS(next_i, next_j, cur_num * 10 + Map[next_i][next_j], cnt + 1);
		}
	}
}

void Solution() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) { 
			DFS(i, j, Map[i][j], 0);
		}
	}
	
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> Map[i][j];

	Solution();
}
