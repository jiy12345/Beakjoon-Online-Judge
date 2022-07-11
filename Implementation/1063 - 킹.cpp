#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수의 상한
L: 수열 길이의 하한

- 변수 제한 사항
 N: 1 ~ 1,000,000,000
 L: 2 ~ 100

- 문제 상황
킹이 다음과 같이 움직일 수 있다고 하고,

R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로

2. 풀이 계획

 1. 이 성에 있는 방의 개수
각각의 방마다 bfs를 진행하며 방문 표시를 하고, 번호를 매기며 방의 개수를 세면 될 듯 하다.

 2. 가장 넓은 방의 넓이
bfs를 진행하며 각각의 방의 넓이를 기록해두고, 그 중 가장 큰 값을 찾으면 될 듯 하다.

 3. 하나의
 각 방에 대한 bfs를 진행하며 해당 방이 어떤 방과 벽을 두고 접하고 있는지를 기록한 뒤,

모든 bfs를 마친 후 두 인접한 방을 합한 넓이의 최대값을 구한다.


3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define ALPHA_TO_INT 64
#define NUM_TO_INT 48

enum DIRECTION { RIGHT, LEFT, DOWN, UP, RIGHT_UP, LEFT_UP, RIGHT_DOWN, LEFT_DOWN };

map<string, int> direction_map = {
	{"R", RIGHT},
	{"L", LEFT},
	{"B", DOWN},
	{"T", UP},
	{"RT", RIGHT_UP},
	{"LT", LEFT_UP},
	{"RB", RIGHT_DOWN},
	{"LB", LEFT_DOWN}
};

int di[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dj[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int N;

bool isInRange(int i, int j) {
	return 1 <= i && i <= 8 && 1 <= j && j <= 8;
}

void solution(pair<int, int> king_startLoc, pair<int, int> stone_startLoc, vector<string> moves) {
	int king_cur_i = king_startLoc.first;
	int king_cur_j = king_startLoc.second;
	int stone_cur_i = stone_startLoc.first;
	int stone_cur_j = stone_startLoc.second;

	for (int i = 0; i < N; i++) {
		int king_next_i = king_cur_i + di[direction_map[moves[i]]];
		int king_next_j = king_cur_j + dj[direction_map[moves[i]]];
		int stone_next_i = stone_cur_i;
		int stone_next_j = stone_cur_j;

		if (isInRange(king_next_i, king_next_j) == false) continue;

		if (king_next_i == stone_next_i && king_next_j == stone_next_j) {
			stone_next_i += di[direction_map[moves[i]]];
			stone_next_j += dj[direction_map[moves[i]]];

			if (isInRange(stone_next_i, stone_next_j) == false) continue;
		}

		king_cur_i = king_next_i;
		king_cur_j = king_next_j;
		stone_cur_i = stone_next_i;
		stone_cur_j = stone_next_j;


	}

	cout << (char)(king_cur_j + ALPHA_TO_INT) << king_cur_i << '\n';
	cout << (char)(stone_cur_j + ALPHA_TO_INT) << stone_cur_i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string king_startLoc_str;
	string stone_startLoc_str;


	cin >> king_startLoc_str >> stone_startLoc_str >> N;
	vector<string>moves(N);
	for (int i = 0; i < N; i++) cin >> moves[i];

	pair<int, int> king_startLoc = { king_startLoc_str[1] - NUM_TO_INT, king_startLoc_str[0] - ALPHA_TO_INT };
	pair<int, int> stone_startLoc = { stone_startLoc_str[1] - NUM_TO_INT, stone_startLoc_str[0] - ALPHA_TO_INT };

	solution(king_startLoc, stone_startLoc, moves);
}