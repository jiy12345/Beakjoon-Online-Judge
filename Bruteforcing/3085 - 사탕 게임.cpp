#include<iostream>
#include<string>
using namespace std;

int N;
string Candy[50];
char Colors[4] = { 'C', 'P', 'Z', 'Y'};

void swap(char&a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

int crossCheck(int rowAndColumnNum, char Color) {
	int maxNum = 0;
	int cntRow = 0;
	int cntColumn = 0;
	for (int k = 0; k < N; k++) {
		if (Candy[rowAndColumnNum][k] == Color) {
			cntRow++;
		}
		else {
			maxNum = max(maxNum, cntRow);
			cntRow = 0;
		}
		if (Candy[k][rowAndColumnNum] == Color) {
			cntColumn++;
		}
		else {
			maxNum = max(maxNum, cntColumn);
			cntColumn = 0;
		}
	}
	maxNum = max(maxNum, cntRow);
	maxNum = max(maxNum, cntColumn);

	return maxNum;
}

int solution() {
	int maxNum = 0;

	// 아무것도 바꾸지 않았을 때 체크
	// 모든 색상에 대해 반복
	for (int i = 0; i < 4; i++) {
		// 행과 열 동시에 체크
		for (int j = 0; j < N; j++) {
			maxNum = max(maxNum, crossCheck(j, Colors[i]));
		}
	}
	
	// 더 커질 수는 없으므로
	if (maxNum == N) {
		return N;
	}

	// 바꿀 수 있는 모든 위치에서 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 오른쪽 끝 좌표가 아니라면 오른쪽과의 교환 진행
			if (j != N - 1) {
				// 오른쪽과 교환
				if (Candy[i][j] != Candy[i][j + 1]) {
					// 교환
					swap(Candy[i][j], Candy[i][j + 1]);

					// 모든 색상에 대해 반복
					for (int k = 0; k < 4; k++) {
						// 최대값의 변동이 있을 수 있는 위치에 대해서만 체크
						maxNum = max(maxNum, crossCheck(i, Colors[k]));
						maxNum = max(maxNum, crossCheck(j, Colors[k]));
						maxNum = max(maxNum, crossCheck(j + 1, Colors[k]));
					}

					// 원상복귀
					swap(Candy[i][j], Candy[i][j + 1]);
				}
			}

			// 아래쪽 끝 좌표가 아니라면 아래쪽과의 교환 진행
			if (i != N - 1) {
				// 아래쪽과 교환
				if (Candy[i + 1][j] != Candy[i][j]) {
					// 교환
					swap(Candy[i + 1][j], Candy[i][j]);

					// 모든 색상에 대해 반복
					for (int k = 0; k < 4; k++) {
						// 최대값의 변동이 있을 수 있는 위치에 대해서만 체크
						maxNum = max(maxNum, crossCheck(i, Colors[k]));
						maxNum = max(maxNum, crossCheck(i + 1, Colors[k]));
						maxNum = max(maxNum, crossCheck(j, Colors[k]));
					}

					// 원상복귀
					swap(Candy[i + 1][j], Candy[i][j]);
				}
			}

			// 더 커질 수는 없으므로
			if (maxNum == N) {
				return N;
			}
		}
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> Candy[i];
	}

	cout << solution();

}
