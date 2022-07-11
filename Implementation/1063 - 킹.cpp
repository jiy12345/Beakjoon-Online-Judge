#include<iostream>
#include<map>
#include<vector>
using namespace std;

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
