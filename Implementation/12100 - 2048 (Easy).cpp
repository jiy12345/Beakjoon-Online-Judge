#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

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

// 각각의 한줄을 이동하는 함수
void moveLine(int startIndex, int endIndex, int curLine, int direction, vector<vector<int>> &curGameBoard) {
	int curPlaced	= startIndex; // 현재 배치되어야 하는 위치
	int prevNum	= 0; // 바로 이전 번호
	
	if (direction == RIGHT || direction == LEFT) {
		for (int j = startIndex; j != endIndex; j += dj[direction]) {
			// 빈칸일 경우 아무 일도 일어나지 않음
			if (curGameBoard[curLine][j] == 0) continue;

			// 합칠수 있는 수를 찾았을 경우
			if (prevNum == curGameBoard[curLine][j]) {
				// 두 수 합한 수 위치에 저장
				curGameBoard[curLine][curPlaced] = prevNum * 2;
				curPlaced += dj[direction];
				// 현 위치의 수 지우기
				curGameBoard[curLine][j] = 0;
				// 한번 합쳐진 수는 다시 합쳐질 수 없으므로
				prevNum = 0;
			}
			else { // 합칠 수 없는 수를 찾았을 경우
				// 이전 수 저장
				if (prevNum != 0) {
					curGameBoard[curLine][curPlaced] = prevNum;
					curPlaced += dj[direction];
				}
				// 합칠 수 있는 수 갱신
				prevNum = curGameBoard[curLine][j];
				// 현재 위치의 수 지우기
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
			// 빈칸일 경우 아무 일도 일어나지 않음
			if (curGameBoard[i][curLine] == 0) continue;

			// 합칠수 있는 수를 찾았을 경우
			if (prevNum == curGameBoard[i][curLine]) {
				// 두 수 합한 수 위치에 저장
				curGameBoard[curPlaced][curLine] = prevNum * 2;
				curPlaced += di[direction];
				// 현 위치의 수 지우기
				curGameBoard[i][curLine] = 0;
				// 한번 합쳐진 수는 다시 합쳐질 수 없으므로
				prevNum = 0;
			}
			else { // 합칠 수 없는 수를 찾았을 경우
				// 이전 수 저장
				if (prevNum != 0) {
					curGameBoard[curPlaced][curLine] = prevNum;
					curPlaced += di[direction];
				}
				// 합칠 수 있는 수 갱신
				prevNum = curGameBoard[i][curLine];
				// 현재 위치의 수 지우기
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
				else						  moveLine(0, N, j, directions[i], curGameBoard);
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
