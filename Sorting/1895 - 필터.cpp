#include<iostream>
#include<algorithm>
using namespace std;

int image[40][40];
int R, C, T;

int solution() {
	int num_of_greater = 0;

	for (int i = 0; i < R - 2; i++) {
		for (int j = 0; j < C - 2; j++) {
			int filter[9];
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					filter[k * 3 + l] = image[i + k][j + l];
				}
			}
			sort(filter, filter + 9);

			if (filter[4] >= T) {
				num_of_greater++;
			}
		}
	}

	return num_of_greater;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> image[i][j];
		}
	}
	cin >> T;

	cout << solution();

}