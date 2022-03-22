#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
W, H: ������ ����, ���� ����

- ���� ���� ����
W, H: 1 ~ 100

.: �� ĭ
*: ��
C: �������� �����ؾ� �ϴ� ĭ

C�� �׻� �ΰ��̸�, �������� ������ �� �ִ� �Է¸� �־�����!

- ���� ��Ȳ
 
 �� ���� c ��ġ�� �����ϱ� ���� ���Ǿ�� �ϴ� �ſ�(90�� ȸ��)�� ������ �ּҰ��� ���Ͽ���

2. Ǯ�� ��ȹ

 �Ϲ����� bfs�� �ٸ���, 90�� ȸ���� ������ üũ�Ѵ�!

 180�� ȸ���� ������ �湮 ǥ�÷� ���� �̷������ ���� ���̹Ƿ�, ��� ȸ���� ����(������ �ٲ� Ƚ��)�� ���� �� �� �ϴ�.



3. ��ȹ ����

bfs�� �׷��� �Ÿ��� ����� ��尡 ���� ���´�.

�Ÿ��� ����� ���� ȸ������ ���ٴ� ���� �����ϴ°�?
�׷��� �ʴ�. ���� priority_queue�� ����Ͽ� ȸ�� ���� ���� ���ĵǵ��� �ؾ��� �� �ϴ�.


*/

enum DIRECTION{ SOUTH, NORTH, EAST, WEST, NUM_OF_DIRECTION };
#define MAX 101

int di[9] = { +1, -1, 0, 0 };
int dj[9] = { 0, 0, +1, -1 };

string Map[MAX];

int W, H;

inline bool isInRange(int i, int j) {
	return 0 <= i && i < H && 0 <= j && j < W;
}

int solution(vector<pair<int, int>> C_Coords) {
	int answer = MAX * MAX;

	vector<vector<vector<int>>>usedNumOfMirror(NUM_OF_DIRECTION, vector<vector<int>>(H, vector<int>(W, MAX * MAX)));
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> bfs_queue;

	int start_i = C_Coords[0].first;
	int start_j = C_Coords[0].second;
	for (int direction = 0; direction < NUM_OF_DIRECTION; direction++) {
		usedNumOfMirror[direction][start_i][start_j] = 0;
	}
	
	int end_i = C_Coords[1].first;
	int end_j = C_Coords[1].second;

	// 4������ �ʱ� �̵� ��Ȳ ��� Ǫ��
	for (int direction = 0; direction < NUM_OF_DIRECTION; direction++) {
		int next_i = start_i + di[direction];
		int next_j = start_j + dj[direction];

		if (!isInRange(next_i, next_j)) continue;

		if (Map[next_i][next_j] != '*') {
			usedNumOfMirror[direction][next_i][next_j] = 0;
			// ����� �ſ��� ���� / ���� ���� / i��ǥ / j��ǥ 
			bfs_queue.push({ 0, direction, next_i, next_j  });
		}
	}



	while (!bfs_queue.empty()) {
		int cur_numOfMirror = bfs_queue.top()[0];
		int prev_direction = bfs_queue.top()[1];
		int cur_i = bfs_queue.top()[2];
		int cur_j = bfs_queue.top()[3];

		bfs_queue.pop();

		//cout << "cur_i: " << cur_i << ", cur_j: " << cur_j << ", cur_numOfMirror: " << cur_numOfMirror << endl;

		if (cur_i == end_i && cur_j == end_j) {
			answer = cur_numOfMirror;
			break;
		}

		for (int cur_direction = 0; cur_direction < NUM_OF_DIRECTION; cur_direction++) {
			int next_numOfMirror = cur_numOfMirror;
			int next_i = cur_i + di[cur_direction];
			int next_j = cur_j + dj[cur_direction];

			if (!isInRange(next_i, next_j)) continue;

			// ���� ��ȯ�� ���� ���
			if (prev_direction != cur_direction) next_numOfMirror++;

			if (Map[next_i][next_j] != '*' && usedNumOfMirror[cur_direction][next_i][next_j] > next_numOfMirror) {
				usedNumOfMirror[cur_direction][next_i][next_j] = next_numOfMirror;

				// ����� �ſ��� ���� / i��ǥ / j��ǥ / ���� ����
				bfs_queue.push({ next_numOfMirror, cur_direction, next_i, next_j });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> C_Coords;

	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		cin >> Map[i];
		for (int j = 0; j < W; j++) if (Map[i][j] == 'C') C_Coords.push_back({ i, j });
	}

	cout << solution(C_Coords);

	return 0;
}
