#include<iostream>
using namespace std;

int bingoBoard[25][25];

bool isWon()
{
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += bingoBoard[i][j];
		}
		if (sum == 0)
			cnt++;
	}

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += bingoBoard[j][i];
		}
		if (sum == 0)
			cnt++;
	}

	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += bingoBoard[i][i];
	if (sum == 0)cnt++;

	sum = 0;
	for (int i = 0; i < 5; i++)
		sum += bingoBoard[i][5 - 1 - i];
	if (sum == 0)cnt++;

	if (cnt >= 3)
		return true;
	else return false;

}

int solution() {
	int cnt = 0;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cnt++;
			int cur_num;
			cin >> cur_num;

			int k, l;
			for (k = 0;k < 5;k++) {
				for (l = 0;l < 5;l++) {
					if (bingoBoard[k][l] == cur_num) {
						bingoBoard[k][l] = 0;
						break;
					}
				}
				if (l != 5) break;
			}

			if (isWon()) {
				return cnt;
			}
		}
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> bingoBoard[i][j];
		}
	}

	cout << solution();
}