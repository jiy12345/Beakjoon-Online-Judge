#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����, ���� ����

- ���� ���� ����
N: 1 ~ 20

- ���� ��Ȳ
 �ִ� 5�� �̵��Ͽ� ���� �� �ִ� ���� ū ����� ���� ���Ͽ���

2. Ǯ�� ��ȹ

1) �ѹ��� ������
�̵� ���⿡ ���� �̵� ������ ������������� ���� ���ڳ��� ��������.
������ �������� ������� ���� ����� ��ġ���� ���ڸ��� �����ϰ� �ȴ�.

3. ��ȹ ����
 1. �˰��� ����


 2. �ð����⵵ ����


 3. �������⵵ ����
*/

#define MAX 20

enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

int di[4] = { -1, +1, 0, 0 };
int dj[4] = { 0, 0, -1, +1 };

int N;
vector<int> directions;

// ������ ������ �̵��ϴ� �Լ�
void moveLine(int startIndex, int endIndex, int curLine, int direction, vector<vector<int>> &curGameBoard) {
	int curPlaced	= startIndex; // ���� ��ġ�Ǿ�� �ϴ� ��ġ
	int prevNum		= 0; // �ٷ� ���� ��ȣ
	
	if (direction == RIGHT || direction == LEFT) {
		for (int j = startIndex; j != endIndex; j += dj[direction]) {
			// ��ĭ�� ��� �ƹ� �ϵ� �Ͼ�� ����
			if (curGameBoard[curLine][j] == 0) continue;

			// ��ĥ�� �ִ� ���� ã���� ���
			if (prevNum == curGameBoard[curLine][j]) {
				// �� �� ���� �� ��ġ�� ����
				curGameBoard[curLine][curPlaced] = prevNum * 2;
				curPlaced += dj[direction];
				// �� ��ġ�� �� �����
				curGameBoard[curLine][j] = 0;
				// �ѹ� ������ ���� �ٽ� ������ �� �����Ƿ�
				prevNum = 0;
			}
			else { // ��ĥ �� ���� ���� ã���� ���
				// ���� �� ����
				if (prevNum != 0) {
					curGameBoard[curLine][curPlaced] = prevNum;
					curPlaced += dj[direction];
				}
				// ��ĥ �� �ִ� �� ����
				prevNum = curGameBoard[curLine][j];
				// ���� ��ġ�� �� �����
				curGameBoard[curLine][j] = 0;
			}
		}
		if (prevNum != 0) {
			curGameBoard[curLine][curPlaced] = prevNum;
			prevNum = 0;
		}
	}
	else {
		for (int i = startIndex; i != endIndex; i += di[direction]) {
			// ��ĭ�� ��� �ƹ� �ϵ� �Ͼ�� ����
			if (curGameBoard[i][curLine] == 0) continue;

			// ��ĥ�� �ִ� ���� ã���� ���
			if (prevNum == curGameBoard[i][curLine]) {
				// �� �� ���� �� ��ġ�� ����
				curGameBoard[curPlaced][curLine] = prevNum * 2;
				curPlaced += di[direction];
				// �� ��ġ�� �� �����
				curGameBoard[i][curLine] = 0;
				// �ѹ� ������ ���� �ٽ� ������ �� �����Ƿ�
				prevNum = 0;
			}
			else { // ��ĥ �� ���� ���� ã���� ���
				// ���� �� ����
				if (prevNum != 0) {
					curGameBoard[curPlaced][curLine] = prevNum;
					curPlaced += di[direction];
				}
				// ��ĥ �� �ִ� �� ����
				prevNum = curGameBoard[i][curLine];
				// ���� ��ġ�� �� �����
				curGameBoard[i][curLine] = 0;
			}
		}
		if (prevNum != 0) {
			curGameBoard[curPlaced][curLine] = prevNum;
			prevNum = 0;
		}
	}
}

int permutationWithRepeatation(vector<vector<int>>gameBoard) {
	int maxNum = 0;

	int curSize = directions.size();
	if (curSize == 5) {
		int maxNum = 0;
		vector<vector<int>>curGameBoard(gameBoard);

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < N; j++) {
				if (directions[i] == UP || directions[i] == LEFT) moveLine(N - 1, -1, j, directions[i], curGameBoard);
				else											  moveLine(0, N, j, directions[i], curGameBoard);
			}
			
		}

		for (int i = 0; i < N; i++) {
			maxNum = max(maxNum, *max_element(curGameBoard[i].begin(), curGameBoard[i].end()));
		}

		return maxNum;
	}

	for (int i = 0; i < 4; i++) {
		directions.push_back(i);
		maxNum = max(maxNum, permutationWithRepeatation(gameBoard));
		directions.pop_back();
	}

	return maxNum;
}

int solution(vector<vector<int>> gameBoard) {
	return permutationWithRepeatation(gameBoard);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<vector<int>> gameBoard(N, vector <int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> gameBoard[i][j];

	cout << solution(gameBoard);
}