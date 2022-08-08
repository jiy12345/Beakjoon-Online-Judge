#include<iostream>
using namespace std;

int isVisited[6][6];

int dRow[8] = { -2, -2, -1, +1, +2, +2, +1, -1 };
int dCol[8] = { -1, +1, +2, +2, +1, -1, -2, -2 };

bool isValidMove(int iDRow, int iDCol) {
	for (int i = 0; i < 8; i++)
		if (dRow[i] == iDRow && dCol[i] == iDCol) return true;
	return false;
}

bool solution() {
	char startCol, startRow;
	char curCol, curRow;
	char prevCol, prevRow;

	cin >> startCol >> startRow;
	prevCol = startCol;
	prevRow = startRow;
	for (int i = 0; i < 35; i++) {
		cin>> curCol >> curRow;

		if (isValidMove(curRow - prevRow, curCol - prevCol) == false)
			return false;

		if (isVisited[curRow - '1'][curCol - 'A'])
			return false;
		else
			isVisited[curRow - '1'][curCol - 'A'] = true;
		
		prevCol = curCol;
		prevRow = curRow;
	}

	if (isValidMove(startRow - curRow, startCol - curCol) == false)
		return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << (solution() ? "Valid" : "Invalid");

	return 0;
}