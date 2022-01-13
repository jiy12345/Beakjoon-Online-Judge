#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
A: 3x3 �迭
r, c: �����ϴ� ���� ��ġ
k: ��ǥ�� �ϴ� ��

- ���� ���� ����
r, c, k: 1~100

- ���� ��Ȳ
A[r][c]�� ����ִ� ���� k�� �Ǳ� ���� ������ �ּ� �ð��� ����Ѵ�. 100�ʰ� ������ A[r][c] = k�� ���� ������ -1�� ����Ѵ�.

2. Ǯ�� ��ȹ
R ����: �迭 A�� ��� �࿡ ���ؼ� ������ �����Ѵ�. ���� ���� �� ���� ������ ��쿡 ����ȴ�.
C ����: �迭 A�� ��� ���� ���ؼ� ������ �����Ѵ�. ���� ���� < ���� ������ ��쿡 ����ȴ�.

R ����� C���� ��� ������ ���� ������ ���� �����Ѵ�.

1. ��(Ȥ�� ��)�� ó������ ������ Ž���ϸ� map�� ���� �� ���� ������ ����.
2. ���� ������ ���� ������������, �� �� �� ��ü�� ���� ������������ �����Ѵ�.
3. ������ map�� �迭�� �Է��Ѵ�. �� ��, ���� �� map���� ª�� map�鿡 ���ؼ� ���� �κ��� 0, 0���� ä���!


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

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

		// R����
		if (rowSize <= columnSize) {
			int curRowSize = 0;
			map<int, int>* mapArr = new map<int, int>[columnSize];

			// ��� ���� ���� �ݺ�
			for (int i = 0; i < columnSize; i++) {
				for (int j = 0; j < rowSize; j++) {
					// ���� ����
					if (A[i][j] != 0) {
						mapArr[i][A[i][j]]++;
					}
				}

				// �� ũ�� ����
				curRowSize = max(curRowSize, (int)mapArr[i].size() * 2);

				// 100���� Ŀ�� ��� 100���� ����
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
		// C����
		else {
			int curColumnSize = 0;
			map<int, int>* mapArr = new map<int, int>[rowSize];

			// ��� �࿡ ���� �ݺ�
			for (int i = 0; i < rowSize; i++) {
				for (int j = 0; j < columnSize; j++) {
					// ���� ����
					if (A[j][i] != 0) {
						mapArr[i][A[j][i]]++;
					}
				}

				// �� ũ�� ����
				curColumnSize = max(curColumnSize, (int)mapArr[i].size() * 2);

				// 100���� Ŀ�� ��� 100���� ����
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

	// 100�ʰ� ������ A[r][c] = k�� ���� ���� ���!
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

	// 0���� �����ϴ� �ε��� ���
	r--;
	c--;

	cout << solution();
}