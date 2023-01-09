#include<iostream>
#include<cstring>
using namespace std;

char input[10][10];

bool is_square_1x1[3][3];
bool is_square_2x2[2][2];
bool is_square_3x3[1][1];

void solution() {
	memset(is_square_1x1, true, sizeof(is_square_1x1));
	memset(is_square_2x2, true, sizeof(is_square_2x2));
	memset(is_square_3x3, true, sizeof(is_square_3x3));
	int num_of_matches_removed = 0;

	// 技肺 己成
	for (int i = 1; i <= 7; i += 3) {
		for (int j = 0; j < 10; j += 3) {
			int cur_i = i / 3;
			int cur_j = j / 3;

			if (input[i][j] == '.') {
				num_of_matches_removed++;

				if (0 <= cur_j && cur_j < 3) {
					is_square_1x1[cur_j][cur_i] = false;
				}
				if (0 <= cur_j - 1 && cur_j - 1 < 3) {
					is_square_1x1[cur_j - 1][cur_i] = false;
				}

				for (int k = 0; k < 2; k++) {
					if (0 <= cur_i - k && cur_i - k < 2) {
						if (0 <= cur_j && cur_j < 2) {
							is_square_2x2[cur_j][cur_i - k] = false;
						}
						if (0 <= cur_j - 2 && cur_j - 2 < 2) {
							is_square_2x2[cur_j - 2][cur_i - k] = false;
						}
					}
				}

				for (int k = 0; k < 1; k++) {
					if (0 <= cur_i - k && cur_i - k < 1) {
						if (0 <= cur_j && cur_j < 1) {
							is_square_3x3[cur_j][cur_i - k] = false;
						}
						if (0 <= cur_j - 3 && cur_j - 3 < 1) {
							is_square_3x3[cur_j - 3][cur_i - k] = false;
						}
					}
				}
			}
		}
	}
	
	// 技肺 己成
	for (int i = 0; i < 10; i += 3) {
		for (int j = 1; j <= 7; j += 3) {
			int cur_i = i / 3;
			int cur_j = j / 3;

			if (input[i][j] == '.') {
				num_of_matches_removed++;

				if (0 <= cur_i && cur_i < 3) {
					is_square_1x1[cur_j][cur_i] = false;
				}
				if (0 <= cur_i - 1 && cur_i - 1 < 3) {
					is_square_1x1[cur_j][cur_i - 1] = false;
				}

				for (int k = 0; k < 2; k++) {
					if (0 <= cur_j - k && cur_j - k < 2) {
						if (0 <= cur_i && cur_i < 2) {
							is_square_2x2[cur_j - k][cur_i] = false;
						}
						if (0 <= cur_i - 2 && cur_i - 2 < 2) {
							is_square_2x2[cur_j - k][cur_i - 2] = false;
						}
					}
				}

				for (int k = 0; k < 1; k++) {
					if (0 <= cur_j - k && cur_j - k < 1) {
						if (0 <= cur_i && cur_i < 1) {
							is_square_3x3[cur_j - k][cur_i] = false;
						}
						if (0 <= cur_i - 3 && cur_i - 3 < 1) {
							is_square_3x3[cur_j - k][cur_i - 3] = false;
						}
					}
				}
			}
		}
	}

	int num_of_squares = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (is_square_1x1[i][j]) {
				num_of_squares++;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (is_square_2x2[i][j]) {
				num_of_squares++;
			}
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			if (is_square_3x3[i][j]) {
				num_of_squares++;
			}
		}
	}

	cout << num_of_matches_removed << " " << num_of_squares;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> input[i][j];
		}
	}

	solution();
}