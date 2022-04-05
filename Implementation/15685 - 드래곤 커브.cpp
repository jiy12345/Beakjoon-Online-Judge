#include<iostream>
#include<vector>
using namespace std;

enum class DIRECTION : int { EAST, NORTH, WEST, SOUTH };

// 반시계 방향 90도 회전
inline constexpr DIRECTION operator++(DIRECTION a) {
	int answer = static_cast<int>(a) + 1;

	if (answer >= 4) return DIRECTION::EAST;
	else return static_cast<DIRECTION>(answer);
}

int dx[4] = { +1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, +1 };

bool map[101][101];

void dragonCurve(int x, int y, int d, int g) {
	vector<DIRECTION> moves;
	moves.push_back(static_cast<DIRECTION>(d));

	int cur_x = x;
	int cur_y = y;

	map[cur_y][cur_x] = true;
	
	// 드래곤 커브의 이동 방향들 계산하기
	for (int i = 0; i < g; i++) {
		int cur_size = moves.size();

		for (int j = cur_size - 1; j >= 0; j--)
			moves.push_back(++moves[j]); // 반시계 방향 90도 회전 시킨 내용을 복사
	}

	// 드래곤 커브에 활용되는 좌표들 표시
	for (int i = 0; i < moves.size(); i++) {
		cur_x = cur_x + dx[static_cast<int>(moves[i])];
		cur_y = cur_y + dy[static_cast<int>(moves[i])];

		map[cur_y][cur_x] = true;
	}
}

inline bool isPartOfDragonCurve(int y, int x) {
	return map[y][x] && map[y + 1][x] && map[y][x + 1] && map[y + 1][x + 1];
}

int solution() {
	int answer = 0;
	int N, x, y, d, g;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;

		dragonCurve(x, y, d, g);
	}

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x])
				if (isPartOfDragonCurve(y, x)) answer++;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << solution();

	return 0;
}
