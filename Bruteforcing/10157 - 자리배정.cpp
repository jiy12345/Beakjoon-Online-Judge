#include<iostream>
using namespace std;

int C, R, K;
enum DIRECTION { UP, RIGHT, DOWN, LEFT, NUM_DIRECTION };
bool is_visited[1002][1002];

int di[4] = { -1, 0, +1, 0 };
int dj[4] = { 0, +1, 0, -1 };

void solution() {
	if (K > R * C) {
		cout << 0;
		return;
	}
	for (int i = 1;i <= R;i++) {
		is_visited[i][C + 1] = true;
		is_visited[i][0] = true;
	}
	for (int i = 1;i <= C;i++) {
		is_visited[R + 1][i] = true;
		is_visited[0][i] = true;
	}

	int cur_i = R;
	int cur_j = 1;
	int cur_direction = UP;
	for (int i = 0;i < K;i++) {
		is_visited[cur_i][cur_j] = true;
		int next_i = cur_i + di[cur_direction];
		int next_j = cur_j + dj[cur_direction];

		if (is_visited[next_i][next_j]) {
			cur_direction = (cur_direction + 1) % NUM_DIRECTION;
			next_i = cur_i + di[cur_direction];
			next_j = cur_j + dj[cur_direction];
		}

		if (i == K - 1) break;

		cur_i = next_i;
		cur_j = next_j;
	}

	cout << cur_j << " " << (R - cur_i + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> C >> R;
	cin >> K;
	solution();
}