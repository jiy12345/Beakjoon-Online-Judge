#include<iostream>
#include<map>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����, ���� ����
K: ����� ����
X: ���� ��ȯ�� �̷������ �ð�
L: ���� ���� ��ȯ Ƚ��

- ���� ���� ����
N: 2 ~ 100
K: 0 ~ 100
X: 0 ~ 10,000
L: 1 ~ 100

- ���� ��Ȳ
 ���� �� �ʸ��� �̵��� �ϴµ� ������ ���� ��Ģ�� �����ٰ� �� ��,

���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.

���� �̸����� ���ٴϴٰ� �� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ������.

������ �� �ʾ� �������� ����϶�

2. Ǯ�� ��ȹ

- ���� �̵�
1) �� ĭ�� ���: 
 1. ������ȯ�� ���� ĭ�� ���: ���� �������� ��ĭ ������ ������, ���� ��ĭ ���̱�
 2. ������ȯ�� �ִ� ĭ�� ���: ������ȯ �ϴ� �������� ��ĭ ������ ������, ���� ��ĭ ���̱�

2) ����� �ִ� ĭ�� ���
 1. ������ȯ�� ���� ĭ�� ���: ���� �������� ��ĭ ������ ������
 2. ������ȯ�� �ִ� ĭ�� ���: ������ȯ �ϴ� �������� ��ĭ ������ ������

- ���� ������ üũ
 ���� ó���� ��� ���� ��, �Ӹ�(���� ��)�� �ִ� ĭ�� �� �Ǵ� �ڱ� �ڽ��� ��� ���� ����

3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
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

		// ������ ���� ó��
		switch (gameBoard[cur_head_i][cur_head_j]) {
		case EMPTY: {
			int cur_tail_i = snakeLocations.front().first;
			int cur_tail_j = snakeLocations.front().second;
			// ���� ��ġ ����
			gameBoard[cur_tail_i][cur_tail_j] = EMPTY;
			snakeLocations.pop();
			break;
		}
		case APPLE:
			// ������ ��ȭ ����
			break;
		case SNAKE:
		case WALL:
			return cur_time;
		}

		// �Ӹ��� ���� ó��
		gameBoard[cur_head_i][cur_head_j] = SNAKE;
		snakeLocations.push({ cur_head_i, cur_head_j });

		// ���� ��ȯ
		curDirection = curDirection + directionChange[cur_time];
		curDirection = (curDirection == -1) ? UP : curDirection;
		curDirection %= DIRECTION_COUNT;
	}
}

void gameBoardSetting() {
	cin >> N >> K;

	// ������ �ܺ� ������ �θ���
	for (int i = 0; i <= N + 1; i++) {
		gameBoard[0][i] = WALL;
		gameBoard[N + 1][i] = WALL;
		gameBoard[i][0] = WALL;
		gameBoard[i][N + 1] = WALL;
	}

	// ��� ��ġ �Է� �ޱ�
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
