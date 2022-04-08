#include <iostream>
#include <vector>
using namespace std;

int arr[6][6];

bool isDice() {
	vector <int> row[6];
	vector <int> column[6];

	//가로 저장
	int numOfRow = 0;
	bool rtf = false;
	for (int i = 0; i < 6; i++) {
		rtf = false;
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] == 1) {
				rtf = true;
				row[numOfRow].push_back(j);
			}
		}
		if (rtf == true)
			numOfRow++;
	}

	//세로 저장
	int ccnt = 0;
	bool ctf = false;
	for (int j = 0; j < 6; j++) {
		ctf = false;
		for (int i = 0; i < 6; i++) {
			if (arr[i][j] == 1) {
				ctf = true;
				column[ccnt].push_back(i);
			}
		}
		if (ctf == true)
			ccnt++;
	}

	if (numOfRow == 3) {
		if (row[1].size() == 4 && row[0].size() == 1 && row[2].size() == 1) return true;

		if (row[1].size() == 3) {
			if (row[0].size() == 2 && (row[0][1] == row[1][0] || row[0][0] == row[1][2])) return true;
			else if (row[2].size() == 2 && (row[2][1] == row[1][0] || row[2][0] == row[1][2])) return true;

		}

		if (row[0].size() == 2 && row[1].size() == 2 && row[2].size() == 2) {
			if ((row[0][1] == row[1][0] && row[1][1] == row[2][0]) || (row[0][0] == row[1][1] && row[1][0] == row[2][1])) return true;
		}

	}

	if (numOfRow == 2) {
		if (row[1].size() == 3) {
			if (row[0].size() == 3 && (row[0][2] == row[1][0] || row[0][0] == row[1][2])) return true;
		}
	}

	if (ccnt == 3) {
		if (column[1].size() == 4 && column[0].size() == 1 && column[2].size() == 1) return true;

		if (column[1].size() == 3) {
			if (column[0].size() == 2 && (column[0][1] == column[1][0] || column[0][0] == column[1][2])) return true;
			else if (column[2].size() == 2 && (column[2][1] == column[1][0] || column[2][0] == column[1][2])) return true;

		}

		if (column[0].size() == 2 && column[1].size() == 2 && column[2].size() == 2) {
			if ((column[0][1] == column[1][0] && column[1][1] == column[2][0]) || (column[0][0] == column[1][1] && column[1][0] == column[2][1])) return true;
		}
	}

	if (ccnt == 2) {
		if (column[1].size() == 3) {
			if (column[0].size() == 3 && (column[0][2] == column[1][0] || column[0][0] == column[1][2])) return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> arr[i][j];
			}
		}

		if (isDice() == true) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}
