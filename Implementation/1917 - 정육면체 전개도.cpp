#include <iostream>
#include <vector>
#include <queue>	
#include <cstring>
using namespace std;

/*
1. 문제 분석
- 변수


- 변수 제한 사항
 세개의 입력 데이터가 주어진다.
 각각의 입력 데이터는 여섯 개의 줄로 이루어져 있다.
 각 데이터는 여섯 개의 줄에 걸쳐 여섯 개의 숫자가 빈 칸을 사이에 두고 주어진다.
 숫자는 0 또는 1로 이루어진다.
 36개의 숫자 중 1은 정확히 6개가 있다.
 정사각형들이 서로 떨어져 있는 경우는 없다.

 0: 공백
 1: 정사각형


- 문제 상황
 세 개의 줄에 걸쳐, 입력된 순서대로 전개도가 정육면체의 전개도이면 yes를, 아니면 no를 출력한다.

2. 풀이 계획
 command 벡터를 만들어서 한 세대를 모두 그린 후

 복사 + 회전하여 뒤에 추가하는 형식으로 진행하면 될 듯 하다.


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int di[4] = { 1, -1, 0, 1 };
int dj[4] = { 0, 0, 1, -1 };
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