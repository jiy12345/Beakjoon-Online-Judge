#include<iostream>
#include<cstring>
using namespace std;

int N;
char hexaBoard[50][50];
int color[50][50];
int answer = 0;

int di[6] = { -1, -1, 0, +1, +1, 0};
int dj[6] = { 0, +1, +1, 0, -1, -1};

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void getColorNum(int cur_i, int cur_j, int cur_color) {
	color[cur_i][cur_j] = cur_color;

	answer = max(answer, 1);

	for (int i = 0; i < 6; i++) {
		int next_i = cur_i + di[i];
		int next_j = cur_j + dj[i];

		if (!isInRange(next_i, next_j)) continue;

		if (hexaBoard[next_i][next_j] == 'X') {
			if (color[next_i][next_j] == -1) {
				getColorNum(next_i, next_j, 1 - cur_color);
			}
			answer = max(answer, 2);

			if (color[next_i][next_j] == cur_color) {
				answer = max(answer, 3);
			}
		}
	}

}

int solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (hexaBoard[i][j] == 'X' && color[i][j] == -1) {
				getColorNum(i, j, 0);
			}
			if (answer == 3) break;
		}
		if (answer == 3) break;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> hexaBoard[i][j];
		}
	}

	memset(color, -1, sizeof(color));
	
	cout << solution();

	return 0;
}
