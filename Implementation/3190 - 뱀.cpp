#include<iostream>
#include<map>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 보드의 가로, 세로 길이
K: 사과의 개수
X: 방향 전환이 이루어지는 시간
L: 뱀의 방향 변환 횟수

- 변수 제한 사항
N: 2 ~ 100
K: 0 ~ 100
X: 0 ~ 10,000
L: 1 ~ 100

- 문제 상황
 뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다고 할 때,

먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.

뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

게임이 몇 초애 끝나는지 계산하라

2. 풀이 계획

- 뱀의 이동
1) 빈 칸일 경우: 
 1. 방향전환이 없는 칸일 경우: 가던 방향으로 한칸 앞으로 보내고, 꼬리 한칸 줄이기
 2. 방향전환이 있는 칸일 경우: 방향전환 하는 방향으로 한칸 앞으로 보내고, 꼬리 한칸 줄이기

2) 사과가 있는 칸일 경우
 1. 방향전환이 없는 칸일 경우: 가던 방향으로 한칸 앞으로 보내기
 2. 방향전환이 있는 칸일 경우: 방향전환 하는 방향으로 한칸 앞으로 보내기

- 종료 조건의 체크
 위의 처리가 모두 끝난 뒤, 머리(가장 앞)가 있는 칸이 벽 또는 자기 자신일 경우 게임 종료

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

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
