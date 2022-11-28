#include<iostream>
using namespace std;

#define ROW 8
#define COL 8

char chessboard[ROW][COL];
int numOfQueen;
int di[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
int dj[8] = { 0, +1, +1, +1, 0, -1, -1, -1 };

bool IsInRange(int i, int j) {
	return 0 <= i && i < ROW && 0 <= j && j < COL;
}

string solution() {
	if (numOfQueen != 8) return "invalid";

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			for (int k = 2; k <= 5; k++) {
				if (chessboard[i][j] == '.') continue;

				int cur_i = i + di[k];
				int cur_j = j + dj[k];
				while (true) {
					if (!IsInRange(cur_i, cur_j))
						break;
					if (chessboard[cur_i][cur_j] == '*')
						return "invalid";
					cur_i += di[k];
					cur_j += dj[k];
				}
			}
		}

	return "valid";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			cin >> chessboard[i][j];
			if (chessboard[i][j] == '*') numOfQueen++;
		}

	cout << solution();
}