#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
A: 3x3 배열
r, c: 관찰하는 값의 위치
k: 목표로 하는 값

- 변수 제한 사항
r, c, k: 1~100

- 문제 상황
A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간을 출력한다. 100초가 지나도 A[r][c] = k가 되지 않으면 -1을 출력한다.

2. 풀이 계획
R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.

R 연산과 C연산 모두 다음과 같은 과정을 거쳐 진행한다.

1. 행(혹은 열)을 처음부터 끝까지 탐색하며 map을 통해 각 수의 개수를 센다.
2. 수의 개수에 대해 오름차순으로, 그 후 수 자체에 대해 오름차순으로 정렬한다.
3. 생성한 map을 배열에 입력한다. 이 때, 가장 긴 map보다 짧은 map들에 대해서 남은 부분은 0, 0으로 채운다!


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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

	for (answer; answer < 100; answer++) {
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