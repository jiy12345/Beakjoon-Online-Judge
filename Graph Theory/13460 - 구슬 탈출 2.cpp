#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum COLOR{RED, BLUE};
enum DIRECTION{LEFT, RIGHT, UP, DOWN};

int di[4] = { 0, 0, -1, +1 };
int dj[4] = { -1, +1, 0, 0 };

int N, M;
bool isVisited[10][10][10][10];
char Map[10][10];
pair<int, int> holeLocation;

void moveMarble(int& i, int& j, DIRECTION direction, COLOR color) {
	// 현 위치 빈 칸으로 표시
	Map[i][j] = '.';

	while (true) {
		i += di[direction];
		j += dj[direction];

		// 막힌 곳을 만났을 경우
		if (Map[i][j] == '#' || Map[i][j] == 'R' || Map[i][j] == 'B') {
			// 한 칸 이전으로 되돌리기
			i -= di[direction];
			j -= dj[direction];

			// Map에 구슬 위치 현 위치로 표시
			Map[i][j] = (color == RED) ? 'R' : 'B';
			break;
		} // 구멍을 만났을 경우
		else if (Map[i][j] == 'O') {
			break; // 그대로 빠져 나가기
		}
	}
}

bool isInHole(int i, int j) {
	return i == holeLocation.first && j == holeLocation.second;
}

int solution(vector<pair<int, int>> locationOfMarbles) {

	int answer = -1;

	queue<pair<int, vector<pair<int, int>>>>bfs_queue;

	bfs_queue.push(make_pair(0, locationOfMarbles));

	
	while (!bfs_queue.empty()) {

		int cur_depth = bfs_queue.front().first;
		int redMarble_cur_i = bfs_queue.front().second[RED].first;
		int redMarble_cur_j = bfs_queue.front().second[RED].second;
		int blueMarble_cur_i = bfs_queue.front().second[BLUE].first;
		int blueMarble_cur_j = bfs_queue.front().second[BLUE].second;
		bfs_queue.pop();

		// 11번 누른 상황이 발생하면 빠져나가기
		if (cur_depth == 11) break;

		// 빨간 구슬만 구멍에 들어갔을 경우
		if (isInHole(redMarble_cur_i, redMarble_cur_j) && !isInHole(blueMarble_cur_i, blueMarble_cur_j)) {
			answer = cur_depth;
			break;
		} // 빨간 구슬만 들어갔을 경우를 제외한 나머지 구슬이 들어간 경우
		else if (isInHole(redMarble_cur_i, redMarble_cur_j) || isInHole(blueMarble_cur_i, blueMarble_cur_j)) {
			// 이 상황에서의 다음 탐색은 진행하지 않음
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int redMarble_next_i = redMarble_cur_i;
			int redMarble_next_j = redMarble_cur_j;
			int blueMarble_next_i = blueMarble_cur_i;
			int blueMarble_next_j = blueMarble_cur_j;

			if (i == LEFT) {
				// 왼쪽에 가까운 것부터 먼저 움직이기
				if (redMarble_cur_j < blueMarble_cur_j) {
					moveMarble(redMarble_next_i, redMarble_next_j, LEFT, RED);
					moveMarble(blueMarble_next_i, blueMarble_next_j, LEFT, BLUE);
				}
				else {
					moveMarble(blueMarble_next_i, blueMarble_next_j, LEFT, BLUE);
					moveMarble(redMarble_next_i, redMarble_next_j, LEFT, RED);
				}
			}
			else if (i == RIGHT) {
				// 오른쪽에 가까운 것부터 먼저 움직이기
				if (redMarble_cur_j > blueMarble_cur_j) {
					moveMarble(redMarble_next_i, redMarble_next_j, RIGHT, RED);
					moveMarble(blueMarble_next_i, blueMarble_next_j, RIGHT, BLUE);
				}
				else {
					moveMarble(blueMarble_next_i, blueMarble_next_j, RIGHT, BLUE);
					moveMarble(redMarble_next_i, redMarble_next_j, RIGHT, RED);
				}
			}
			else if (i == UP) {
				// 위쪽에 가까운 것부터 먼저 움직이기
				if (redMarble_cur_i < blueMarble_cur_i) {
					moveMarble(redMarble_next_i, redMarble_next_j, UP, RED);
					moveMarble(blueMarble_next_i, blueMarble_next_j, UP, BLUE);
				}
				else {
					moveMarble(blueMarble_next_i, blueMarble_next_j, UP, BLUE);
					moveMarble(redMarble_next_i, redMarble_next_j, UP, RED);
				}
			}
			else if (i == DOWN) {
				// 아래쪽에 가까운 것부터 먼저 움직이기
				if (redMarble_cur_i > blueMarble_cur_i) {
					moveMarble(redMarble_next_i, redMarble_next_j, DOWN, RED);
					moveMarble(blueMarble_next_i, blueMarble_next_j, DOWN, BLUE);
				}
				else {
					moveMarble(blueMarble_next_i, blueMarble_next_j, DOWN, BLUE);
					moveMarble(redMarble_next_i, redMarble_next_j, DOWN, RED);
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << Map[i][j];
				}
				cout << endl;
			}

			// 구슬끼리의 충돌을 대비한 표시 지워주기
			if (Map[redMarble_next_i][redMarble_next_j] != 'O') Map[redMarble_next_i][redMarble_next_j] = '.';
			if (Map[blueMarble_next_i][blueMarble_next_j] != 'O') Map[blueMarble_next_i][blueMarble_next_j] = '.';

			// 두 구슬의 위치가 나오지 않았던 상황일 때만 탐색 진행
			if (!isVisited[redMarble_next_i][redMarble_next_j][blueMarble_next_i][blueMarble_next_j]) {
				isVisited[redMarble_next_i][redMarble_next_j][blueMarble_next_i][blueMarble_next_j] = true;
				bfs_queue.push({ cur_depth + 1, {{redMarble_next_i, redMarble_next_j}, {blueMarble_next_i, blueMarble_next_j}} });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> locationOfMarbles(2);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			if (row[j] == 'R') locationOfMarbles[RED] = make_pair(i, j);
			if (row[j] == 'B') locationOfMarbles[BLUE] = make_pair(i, j);
			if (row[j] == 'O') holeLocation = make_pair(i, j);

			Map[i][j] = row[j];
		}
	}

	cout << solution(locationOfMarbles);

	return 0;
}
