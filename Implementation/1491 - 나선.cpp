#include<iostream>
using namespace std;

bool isVisited[5000][5000];
int N, M;

enum DIRECTION { EAST, NORTH, WEST, SOUTH, NUM_DIRECTION };

int di[4] = { 0, -1, 0, 1 };
int dj[4] = { 1, 0, -1, 0 };

bool IsInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

void solution() {
	int cur_i = 0;
	int cur_j = 0;
	int cur_direction = NORTH;

	while (true) {
		isVisited[cur_i][cur_j] = true;
		int next_i = cur_i + di[cur_direction];
		int next_j = cur_j + dj[cur_direction];

		if (!IsInRange(next_i, next_j) || isVisited[next_i][next_j]) {
			int i;
			for (i = 0; i < NUM_DIRECTION; i++) {
				cur_direction = (cur_direction + 1) % NUM_DIRECTION;
				next_i = cur_i + di[cur_direction];
				next_j = cur_j + dj[cur_direction];

				if (IsInRange(next_i, next_j) && !isVisited[next_i][next_j]) {
					break;
				}
			}

			if (i == NUM_DIRECTION) break;
		}

		cur_i = next_i;
		cur_j = next_j;
	}
	
	cout << cur_i << " " << cur_j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	solution();
}