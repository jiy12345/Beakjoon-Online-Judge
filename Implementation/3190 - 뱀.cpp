#include<iostream>
#include<map>
#include<queue>
using namespace std;

#define MAX 100
#define MAX_TIME 10000

enum GAME_BOARD_STATE {
	EMPTY,
	APPLE,
	WALL,
	SNAKE
};

map<char, int> directionChangeMap = { {'L', -1}, {'D', +1} };

enum DIRECTION {
	RIGHT,
	DOWN,
	LEFT,
	UP,
	DIRECTION_COUNT
};

int di[4] = { 0, +1, 0, -1 };
int dj[4] = { +1, 0, -1, 0 };

int gameBoard[MAX + 2][MAX + 2];
int directionChange[MAX_TIME];
int N, K, L;



int solution() {
	int curDirection = RIGHT;
	int cur_time = 0;
	
	queue<pair<int, int>> snakeLocations;

	// snake state
	int cur_head_i = 1;
	int cur_head_j = 1;

	snakeLocations.push({ cur_head_i, cur_head_j });

	while (true) {
		cur_time++;
		cur_head_i += di[curDirection];
		cur_head_j += dj[curDirection];

		// 꼬리에 대한 처리
		switch (gameBoard[cur_head_i][cur_head_j]) {
		case EMPTY: {
			int cur_tail_i = snakeLocations.front().first;
			int cur_tail_j = snakeLocations.front().second;
			// 꼬리 위치 비우기
			gameBoard[cur_tail_i][cur_tail_j] = EMPTY;
			snakeLocations.pop();
			break;
		}
		case APPLE:
			// 꼬리는 변화 없음
			break;
		case SNAKE:
		case WALL:
			return cur_time;
		}

		// 머리에 대한 처리
		gameBoard[cur_head_i][cur_head_j] = SNAKE;
		snakeLocations.push({ cur_head_i, cur_head_j });

		// 방향 전환
		curDirection = curDirection + directionChange[cur_time];
		curDirection = (curDirection == -1) ? UP : curDirection;
		curDirection %= DIRECTION_COUNT;
	}
}

void gameBoardSetting() {
	cin >> N >> K;

	// 게임판 외부 벽으로 두르기
	for (int i = 0; i <= N + 1; i++) {
		gameBoard[0][i] = WALL;
		gameBoard[N + 1][i] = WALL;
		gameBoard[i][0] = WALL;
		gameBoard[i][N + 1] = WALL;
	}

	// 사과 위치 입력 받기
	int apple_i, apple_j;
	for (int i = 0; i < K; i++) {
		cin >> apple_i >> apple_j;
		gameBoard[apple_i][apple_j] = APPLE;
	}
}

void directionChangeSetting() {
	cin >> L;

	int cur_time;
	char cur_directionChange;
	for (int i = 0; i < L; i++) {
		cin >> cur_time >> cur_directionChange;
		directionChange[cur_time] = directionChangeMap[cur_directionChange];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	gameBoardSetting();
	directionChangeSetting();

	cout << solution();
}
