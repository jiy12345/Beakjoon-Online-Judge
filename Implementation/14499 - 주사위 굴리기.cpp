#include<iostream>
#include<vector>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ���� ����
M: ������ ���� ����
r, c: ������ ��ǥ
x, y: �ֻ����� ó�� ���� ���� ��ǥ
K: ����� ����

- ���� ���� ����
N, M: 1 ~20
N, M�� ¦��
R: 1 ~ 1,000
Aij: 1 ~ 10,000,000

- ���� ��Ȳ
 �����̿� ������ ��ġ�� �־�����, �����̴� ������ ���� �̵��Ѵٰ� ����.

 �������� �� ��ġ�� X�� ��,

 - �ȱ�: 1���Ŀ� X - 1 or X + 1
 - �����̵�: 0�� �Ŀ� 2 * X

 �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

2. Ǯ�� ��ȹ

0 - 1 �� ������ ���� �ٸ� ����ġ�� ������ �ֱ�� ������,

�켱���� ť�� �̵��Ѵٸ�?
 => � ��带 ���� �湮 �ߴٰ� ���� ��, �� �湮���� �ɸ� �ð��� �ִܽð��̶�� ������ �� ���� ������ �ȵȴ�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

enum DIRECTION { EAST, WEST, NORTH, SOUTH };

int dx[4] = { 0, 0, -1, +1 };
int dy[4] = { +1, -1, 0, 0 };

int map[20][20];
int N, M, x, y, K;

bool isInRange(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

class Dice {
public:
	int top = 0;
	int bottom = 0;
	int east = 0;
	int west = 0;
	int north = 0;
	int south = 0;

	void moveEast() {
		int temp = east;
		east = top;
		top = west;
		west = bottom;
		bottom = temp;
	}
		
	void moveWest() {
		int temp = west;
		west = top;
		top = east;
		east = bottom;
		bottom = temp;
	}
		
	void moveNorth() {
		int temp = north;
		north = top;
		top = south;
		south = bottom;
		bottom = temp;
	}

	void moveSouth() {
		int temp = south;
		south = top;
		top = north;
		north = bottom;
		bottom = temp;
	}

	void moveDice(int command) {
		switch (command) {
		case EAST:
			moveEast();
			break;
		case WEST:
			moveWest();
			break;
		case NORTH:
			moveNorth();
			break;
		case SOUTH:
			moveSouth();
			break;
		}
	}

};


void solution() {
	Dice dice;

	int command;

	for (int i = 0; i < K; i++) {
		cin >> command;

		command -= 1;

		x += dx[command];
		y += dy[command];

		if (isInRange(x, y)) {
			dice.moveDice(command);

			if (map[x][y] == 0) {
				map[x][y] = dice.bottom;
			}
			else {
				dice.bottom = map[x][y];
				map[x][y] = 0;
			}

			cout << dice.top << '\n';
		}
		else {
			x -= dx[command];
			y -= dy[command];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	solution();

	return 0;
}