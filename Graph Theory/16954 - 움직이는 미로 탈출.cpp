#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N, M: ����� ����, ���� ����
K: ���� �μ� �� �ִ� Ƚ��

 - ���� ���� ����
N, M: 1 ~ 1,000
K: 1 ~ 10

(1, 1)�� (N, M)�� �׻� �� �����̴�!

- ���� ��Ȳ
��ĭ�� ������ �̷���� 8 x 8 ü���ǿ��� ĳ���ʹ� ���� ���� �Ʒ� ĭ�� ������, ���� ������ �� ĭ���� �̵��ؾ� �Ѵٰ� �� ��,
ĳ���Ͱ� ������ �� ĭ���� �̵��� �� �ִ��� ���θ� ���϶�.

- ���� ������ ���� ��Ģ�� ���� �����δ�.
 1) 1�ʸ��� ��� ���� �Ʒ��� �ִ� ������ ��ĭ�� ��������.
 2) ���� �Ʒ��� �־ �Ʒ��� ���� ���ٸ� ���� ������� �ȴ�.

- ĳ���ʹ� ������ ���� ��Ģ�� ���� �����δ�.
 1) ĳ���ʹ� ������ �� ĭ �Ǵ� �밢�� �������� �̵��ϰų�, ���� ��ġ�� �� ���� �� �ִ�.
 2) �̵��� ���� �� ĭ���θ� �̵��� �� �ִ�.

- 1�� ���� ĳ���Ͱ� ���� �̵��ϰ�, �� ���� ���� �̵��Ѵ�.
- ���� ĳ���Ͱ� �ִ� ĭ���� �̵��ϸ� �� �̻� ĳ���ʹ� �̵��� �� ����.

2. Ǯ�� ��ȹ
 ������ �ִ� ��θ� ���ϴ� ������ �ƴϹǷ� depth�� �ʿ� ������, ���� �ٸ� Ÿ�ֿ̹� �����Ѵٸ� ����� �޶��� �� �����Ƿ� üũ�ؾ� �� ���ϴ�.

 ���δٸ� ������ ���� ��带 �湮�ϴ� ��쵵 �ٸ� ���� ������ �� �ϴ�.

 ���� 

 1. ���� �Է¹޴´�.

 2. bfs�� �����Ѵ�.
  - �ʿ��� ����: i, j, depth
  - �湮 ǥ��: i, j, depth

   => �� ���� depth�� 30�� ���� ���� ������ ���̹Ƿ�(8���̸� �ʿ��� ��� ���� ������µ�, �� ���� �Ÿ��� ������ 14 �̹Ƿ�)

   => �� ��, ���� �������� ��� ǥ���ؾ� �ұ�?
   => Ÿ�̹��� 8���ۿ� ���� �����Ƿ�, ���� 



3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define BLANK false
#define WALL  true
#define MAX   8

int di[9] = { +1, -1, 0, 0, +1, -1, +1, -1, 0 };
int dj[9] = { 0, 0, +1, -1, +1, +1, -1, -1, 0 };

string Map[8];

// �� ������ ��
bool mapOverTime[MAX][MAX][9];
bool isVisited[MAX][MAX][30];

void calCulateMapOverTime() {
	// ������ 8 ������ ������ ��� ���� ����� ��ĭ�̹Ƿ�
	// �������� ������ ��� ������ ���� �ݺ�
	for (int i = 0; i < MAX; i++) {
		// �� �������� ���� ���� �޶���
		for (int j = i; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				if (Map[j - i][k] == '#') mapOverTime[j][k][i] = true;
			}
		}
	}
}

inline bool isInRange(int i, int j) {
	return 0 <= i && i < MAX && 0 <= j && j < MAX;
}

int solution() {
	int answer = 0;

	queue<vector<int>> bfs_queue;

	// ó������ i��ǥ / j��ǥ / ����(�ش� ��带 �湮�� Ÿ�̹�)
	bfs_queue.push({ MAX - 1, 0, 0, });
	isVisited[MAX - 1][0][0] = true;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_time = bfs_queue.front()[2];
		bfs_queue.pop();
		
		cout << "cur_i: " << cur_i << ", cur_j: " << cur_j << ", cur_time: " << cur_time << endl;

		if (cur_i == 0 && cur_j == MAX - 1) {
			answer = 1;
			break;
		}

		// 8 ���� �ð��뿡�� ��� ���� ������Ƿ�, �ǹ̰� ����
		if (cur_time > 8) cur_time = 8;

		for (int i = 0; i < 9; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			int next_time = cur_time + 1;

			// ������ ����� ��ġ�� Ž�� �������� ����
			if (!isInRange(next_i, next_j)) continue;

			// 8 ���� �ð��뿡�� ��� ���� ������Ƿ�, �ǹ̰� ����
			if (next_time > 8) next_time = 8;

			if (mapOverTime[next_i][next_j][cur_time] == BLANK && // ���� �ð��� ���� �ƴϸ�,
				mapOverTime[next_i][next_j][next_time] == BLANK && // ���� �ð����� ���� �ƴϸ�,
				isVisited[next_i][next_j][next_time] == false) { // ���� �ð��� �湮���� ���� ����� ��쿡�� Ž��
				isVisited[next_i][next_j][next_time] = true;
				bfs_queue.push({ next_i, next_j, next_time });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> Map[i];

	calCulateMapOverTime();

	for (int i = 0; i < MAX; i++) {
		// �� �������� ���� ���� �޶���
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				cout << mapOverTime[j][k][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << solution();

	return 0;
}
