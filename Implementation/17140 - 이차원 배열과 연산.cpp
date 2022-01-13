#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, k;
int A[100][100];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

long long solution() {
	int answer = 0;

	int rowSize = 3;
	int columnSize = 3;

	for (answer; answer <= 100; answer++) {
		if (A[r][c] == k) {
			break;
		}

		// R연산
		if (rowSize <= columnSize) {
			int curRowSize = 0;
			map<int, int>* mapArr = new map<int, int>[columnSize];

			// 모든 열에 대해 반복
			for (int i = 0; i < columnSize; i++) {
				for (int j = 0; j < rowSize; j++) {
					// 개수 세기
					if (A[i][j] != 0) {
						mapArr[i][A[i][j]]++;
					}
				}

				// 행 크기 갱신
				curRowSize = max(curRowSize, (int)mapArr[i].size() * 2);

				// 100보다 커질 경우 100으로 설정
				if (curRowSize > 100) curRowSize = 100;
			}

			rowSize = curRowSize;

			for (int i = 0; i < columnSize; i++) {
				vector<pair<int, int>> vec(mapArr[i].begin(), mapArr[i].end());
				sort(vec.begin(), vec.end(), cmp);
				for (int j = 0; j < rowSize; j++) {
					if (j < vec.size()) {
						A[i][2 * j] = vec[j].first;
						A[i][2 * j + 1] = vec[j].second;
					}
					else {
						A[i][2 * j] = 0;
						A[i][2 * j + 1] = 0;
					}
				}
			}

			rowSize = curRowSize;

			delete[](mapArr);
		}
		// C연산
		else {
			int curColumnSize = 0;
			map<int, int>* mapArr = new map<int, int>[rowSize];

			// 모든 행에 대해 반복
			for (int i = 0; i < rowSize; i++) {
				for (int j = 0; j < columnSize; j++) {
					// 개수 세기
					if (A[j][i] != 0) {
						mapArr[i][A[j][i]]++;
					}
				}

				// 열 크기 갱신
				curColumnSize = max(curColumnSize, (int)mapArr[i].size() * 2);

				// 100보다 커질 경우 100으로 설정
				if (curColumnSize > 100) curColumnSize = 100;
			}

			columnSize = curColumnSize;

			for (int i = 0; i < rowSize; i++) {
				vector<pair<int, int>> vec(mapArr[i].begin(), mapArr[i].end());
				sort(vec.begin(), vec.end(), cmp);
				for (int j = 0; j < columnSize; j++) {
					if (j < vec.size()) {
						A[2 * j][i] = vec[j].first;
						A[2 * j + 1][i] = vec[j].second;
					}
					else {
						A[2 * j][i] = 0;
						A[2 * j + 1][i] = 0;
					}
				}
			}

			delete[](mapArr);
		}
	}

	// 100초가 지나도 A[r][c] = k가 되지 않은 경우!
	if (answer == 100) {
		answer = -1;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}

	// 0부터 시작하는 인덱스 사용
	r--;
	c--;

	cout << solution();
}
