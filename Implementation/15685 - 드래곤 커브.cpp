#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 드래곤 커브의 개수

 드래곤 커브 정보
x, y: 드래곤 커브의 시작 좌표
d: 시작 방향
g: 세대

- 변수 제한 사항
N: 1 ~ 20

 드래곤 커브 정보
x, y: 0 ~ 100
d: 0 ~ 3
0: x좌표가 증가하는 방향 (→)
1: y좌표가 감소하는 방향 (↑)
2: x좌표가 감소하는 방향 (←)
3: y좌표가 증가하는 방향 (↓)

g: 0 ~ 10

입력으로 주어지는 드래곤 커브는 격자 밖으로 벗어나지 않는다.
드래곤 커브는 서로 겹칠 수 있다.


- 문제 상황
 크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 구하라.

2. 풀이 계획
 command 벡터를 만들어서 한 세대를 모두 그린 후 
 
 복사 + 회전하여 뒤에 추가하는 형식으로 진행하면 될 듯 하다. 


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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