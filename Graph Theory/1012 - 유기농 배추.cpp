#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
M, N: ���߹��� ���α���, ���α���
K: ���߰� �ɾ��� �ִ� ��ġ�� ����
X, Y: ������ ��ġ�� ǥ���ϴ� ��ǥ

- ���� ���� ����
M, N: 1~50
K: 1~M*N

�� ������ ��ġ�� ���� ���� ����.

- ���� ��Ȳ
 �����¿� �� ���⿡ �ٸ� ���߰� ��ġ�� ��� ���� �������ִٰ� �� ��, ���� �������̴� ������ ���ߵ鰣���� �̵��Ͽ� ������ ������ �� �ִ�.

�� �� �־��� ���� ���ǿ� �� ����� �����������̰� �ʿ����� ���϶�.

2. Ǯ�� ��ȹ
�ߺ����� �湮�ϴ� BFS�� �����ϸ� �� �� ����, ���� �ִܰŸ� ���� ���ϴ� ���� �ƴϹǷ� ���� ���̸� �� �ʿ�� ������ �ϴ�.

���� �ڼ��� ��ȹ�� ������ ����.

1. 2���� �迭�� �� ������ ��ġ�� 1��, ���߰� ���� ��ġ�� 0���� �Ͽ� �Է¹޴´�.
2. ���߹��� ��� ��ġ�� Ž���ϸ�, ���߰� �ִ� ��ġ�� ���ؼ��� BFS�� �����Ѵ�.
 => �� �� BFS�� Ž���� ��ġ�� 0���� ǥ�ø� �ٲ۴�.
3. BFS�� ����� Ƚ���� �� ����Ѵ�.

3. ��ȹ ����


*/

int M, N, K;
int cabbage_field[50][50] = { {0,} }; // ���߹��� ǥ���� �迭

//         �Ʒ�, ��, ������, ����
int di[4] = { +1, -1,  0,  0 };
int dj[4] = { 0,  0, +1, -1 };

void bfs(vector<int> start_node) {
	queue<vector<int>> bfs_queue;

	bfs_queue.push(start_node);

	cabbage_field[start_node[0]][start_node[1]] = 0;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];

		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			// ���� ��尡 ���� ���� ��쿡�� ����
			if (0 <= next_i && next_i < M && 0 <= next_j && next_j < N) {
				// ���� ��尡 ���߰� �ִ� ����� ��쿡�� ť�� push�ϸ� �湮 ǥ��
				if (cabbage_field[next_i][next_j] == 1) {
					cabbage_field[next_i][next_j] = 0;
					bfs_queue.push({ next_i, next_j });
				}
			}
		}
	}
	
}

int solution() {
	int answer = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			// ���߰� ���� ��쿡�� BFS ����
			if (cabbage_field[i][j] == 1) {

				cout << endl;
				answer++; // �ϳ��� ���� ������ �� �ִ� ���̹Ƿ� �������� ���� �� �߰�
				bfs({ i, j });
			}
		}
	}

	return answer;
}

int main() {
	int T;
	int X, Y;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			cabbage_field[X][Y] = 1;
		}
		cout<< solution() << '\n';
	}
}