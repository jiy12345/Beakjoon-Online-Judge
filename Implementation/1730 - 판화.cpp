#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

#define MAX_MAP_SIZE 10

enum DIRECTION{ UP, DOWN, LEFT, RIGHT};
enum SYMBOL{ EMPTY, VERTICAL_LINE, HORIZONTAL_LINE, CROSS_LINE};

map<char, int> directionMap = {
	{'U', UP},
	{'D', DOWN},
	{'L', LEFT},
	{'R', RIGHT}
};

map<int, char> intToSymbol = {
	{0b0000, '.'},
	{0b0001, '|'},
	{0b0010, '-'},
	{0b0011, '+'},
};

int di[4] = { -1, +1, 0, 0 };
int dj[4] = { 0, 0, -1, +1 };

char woodenPlatter[10][10];
int N;

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void solution() {
	int cur_i = 0;
	int cur_j = 0;

	cin.ignore();
	while (true) {
		char curCommand = getchar();
		if (curCommand == '\n') break;

		int curDirection = directionMap[curCommand];
		int next_i = cur_i + di[curDirection];
		int next_j = cur_j + dj[curDirection];

		if (isInRange(next_i, next_j) == false) continue;

		if (curDirection == UP || curDirection == DOWN) {
			woodenPlatter[cur_i][cur_j] |= VERTICAL_LINE;
			woodenPlatter[next_i][next_j] |= VERTICAL_LINE;
		}
		else {
			woodenPlatter[cur_i][cur_j] |= HORIZONTAL_LINE;
			woodenPlatter[next_i][next_j] |= HORIZONTAL_LINE;
		}


		cur_i = next_i;
		cur_j = next_j;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << intToSymbol[woodenPlatter[i][j]];
		cout << '\n';
	}
}

int main() {
	cin >> N;

	solution();

	return 0;
}