#include <iostream>
using namespace std;

int R, C;
char table[100][100];

int isInRange(int i, int j) {
	return 0 <= i && i < R && 0 <= j && j < C;
}
void solution() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (table[i][j] == '*') {
				for (int n = i - 1; n <= i + 1; n++) {
					for (int m = j - 1; m <= j + 1; m++) {
						if (!isInRange(n, m)) continue;
						if (n == i && m == j) continue;
						if (table[n][m] == '*') continue;
						table[n][m]++;
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << table[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(true) {
		cin >> R >> C;

		if (R == 0 && C == 0) break;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				cin >> table[i][j];
				if (table[i][j] == '.') table[i][j] = '0';
			}
				
		solution();
	}
}