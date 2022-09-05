#include<iostream>
#include<memory.h>
#include<string>
using namespace std;

#define MAX 21

int T;
int R, C;
char board[MAX][MAX];

enum DIRECTION { RIGHT, DOWN, LEFT, UP, NUM_OF_DIRECTION };
int di[4] = { 0, +1, 0, -1 };
int dj[4] = { +1, 0, -1, 0 };

bool canGo(int i, int j) {
	if (board[i][j] == -1) return false;

	return 0 <= i && i < R && 0 <= j && j < C;
}

string solution() {
	string answer = "";
	int cur_i = 0;
	int cur_j = 0;
	int cur_direction = RIGHT;
	int cur_num = 0;

	int cnt = 0;
	int cur_order = 4;
	while (true) {
		cur_num += ((board[cur_i][cur_j] - '0') << cur_order--);
		board[cur_i][cur_j] = -1;

		if (cur_order == -1) {
			if (cur_num == 0) answer += " ";
			else			  answer += cur_num + 'A' -1;
			cur_order = 4;
			cur_num = 0;

		}

		int next_i = cur_i + di[cur_direction];
		int next_j = cur_j + dj[cur_direction];
		if (canGo(next_i, next_j)) {
			cur_i = next_i;
			cur_j = next_j;
		}
		else {
			cur_direction = (cur_direction + 1) % NUM_OF_DIRECTION;
			cur_i += di[cur_direction];
			cur_j += dj[cur_direction];
		}

		cnt++;
		if (cnt == R * C) break;
	}
	
	int curLoc = answer.size() - 1;
	for (curLoc; curLoc >= 0; curLoc--) {

		if (answer[curLoc] != ' ') break;
	}

	answer = answer.substr(0, curLoc + 1);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	
	memset(board, -1, sizeof(board));
	for (int i = 0; i < T; i++) {
		cin >> R >> C;

		for (int j = 0; j < R; j++) 
			for (int k = 0; k < C; k++)
				cin >> board[j][k];

		cout << solution() << '\n';
	}
}