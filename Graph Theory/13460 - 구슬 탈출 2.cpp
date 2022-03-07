#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*
1. ���� �м�
- ����
N: ������ ���� ����
M: ������ ���� ����

- ���� ���� ����
N, M: 3 ~ 10

- ���� ��Ȳ
����� ���̳� ��ĭ���� �̷���� �ְ�,

������ �� ���� ��ĭ�� ������ �ְ�,

 �� ������ "����", "������", "��", "�Ʒ�"�� ���� 4���� �������� �̵��� �� ������,

������ ������ ���� �̵��Ѵٰ� �� ��,

- ������ �̵��Ϸ��� ĭ�� ���̸�, ������ �̵����� �ʴ´�.
- ������ �̵��Ϸ��� ���⿡ ĭ�� ������ ������ ���� �ٱ����� ��������.
- �� ���� ��쿡�� �̵��Ϸ��� �������� �� ĭ �̵��Ѵ�.�̵��Ϸ��� ĭ�� ������ �ִ� ��쿡�� �� ĭ �̵��Ѵ�.

 �� ���� �� �ϳ��� ���忡�� ����߸��� ���� �ؾ��ϴ� �̵��� �ּ� Ƚ���� ����Ѵ�.

 ���� �� ������ ����߸� �� ���ų�, ����߸��� ���� ��ư�� 10������ ���� ������ �Ѵٸ� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

enum COLOR{RED, BLUE};
enum DIRECTION{LEFT, RIGHT, UP, DOWN};

int di[4] = { 0, 0, -1, +1 };
int dj[4] = { -1, +1, 0, 0 };

int N, M;
bool isVisited[10][10][10][10];
char Map[10][10];
pair<int, int> holeLocation;

void moveMarble(int& i, int& j, DIRECTION direction, COLOR color) {
	// �� ��ġ �� ĭ���� ǥ��
	Map[i][j] = '.';

	while (true) {
		i += di[direction];
		j += dj[direction];

		// ���� ���� ������ ���
		if (Map[i][j] == '#' || Map[i][j] == 'R' || Map[i][j] == 'B') {
			// �� ĭ �������� �ǵ�����
			i -= di[direction];
			j -= dj[direction];

			// Map�� ���� ��ġ �� ��ġ�� ǥ��
			Map[i][j] = (color == RED) ? 'R' : 'B';
			break;
		} // ������ ������ ���
		else if (Map[i][j] == 'O') {
			break; // �״�� ���� ������
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

		// 11�� ���� ��Ȳ�� �߻��ϸ� ����������
		if (cur_depth == 11) break;

		// ���� ������ ���ۿ� ���� ���
		if (isInHole(redMarble_cur_i, redMarble_cur_j) && !isInHole(blueMarble_cur_i, blueMarble_cur_j)) {
			answer = cur_depth;
			break;
		} // ���� ������ ���� ��츦 ������ ������ ������ �� ���
		else if (isInHole(redMarble_cur_i, redMarble_cur_j) || isInHole(blueMarble_cur_i, blueMarble_cur_j)) {
			// �� ��Ȳ������ ���� Ž���� �������� ����
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int redMarble_next_i = redMarble_cur_i;
			int redMarble_next_j = redMarble_cur_j;
			int blueMarble_next_i = blueMarble_cur_i;
			int blueMarble_next_j = blueMarble_cur_j;

			if (i == LEFT) {
				// ���ʿ� ����� �ͺ��� ���� �����̱�
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
				// �����ʿ� ����� �ͺ��� ���� �����̱�
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
				// ���ʿ� ����� �ͺ��� ���� �����̱�
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
				// �Ʒ��ʿ� ����� �ͺ��� ���� �����̱�
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

			// ���������� �浹�� ����� ǥ�� �����ֱ�
			if (Map[redMarble_next_i][redMarble_next_j] != 'O') Map[redMarble_next_i][redMarble_next_j] = '.';
			if (Map[blueMarble_next_i][blueMarble_next_j] != 'O') Map[blueMarble_next_i][blueMarble_next_j] = '.';

			// �� ������ ��ġ�� ������ ���� ��Ȳ�� ���� Ž�� ����
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