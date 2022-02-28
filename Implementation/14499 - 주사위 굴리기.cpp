#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 지도의 세로 길이
M: 지도의 가로 길이
r, c: 지도의 좌표
x, y: 주사위를 처음 놓은 곳의 좌표
K: 명령의 개수

- 변수 제한 사항
N, M: 1 ~20
N, M은 짝수
R: 1 ~ 1,000
Aij: 1 ~ 10,000,000

- 문제 상황
 수빈이와 동생의 위치가 주어지고, 수빈이는 다음과 같이 이동한다고 하자.

 수빈이의 현 위치가 X일 때,

 - 걷기: 1초후에 X - 1 or X + 1
 - 순간이동: 0초 후에 2 * X

 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

2. 풀이 계획

0 - 1 로 간선이 서로 다른 가중치를 가지고 있기는 하지만,

우선순위 큐를 이동한다면?
 => 어떤 노드를 먼저 방문 했다고 했을 때, 그 방문까지 걸린 시간이 최단시간이라고 보장할 수 없기 때문에 안된다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

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