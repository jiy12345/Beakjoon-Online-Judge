#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
 N: �������� ����, ���α���

- ���� ���� ����
 N: 3~16
 �� ��ġ�� ��: 1 = ��, 0 = ��ĭ

- ���� ��Ȳ
�������� ������ ������ 3�����̸�, �������� �� ������ �� �̵� ������ ������ ������ ���ٰ� �� ��,

����: ����, ���ϴ�
����: �ϴ�, ���ϴ�
�밢��: �ϴ�, ���ϴ�, ����

�������� (1, 1)�� (1, 2)�� �����ϰ� �ְ�, ������ �����̴�. �������� ���� ���� (N, N)�� �̵���Ű�� ����� ������ ���غ���.

2. Ǯ�� ��ȹ
 �̵���ų �� �ִ� ����� ���� ���ϴ� ���̹Ƿ�, DFS�� �õ��ϰų�, pop�� �� �湮ǥ�ø� �ϴ� BFS�� �õ��ؾ� �� �� �ϴ�!

=> �������� �������� �̵��ϰų� ȸ���� ���� �ִٸ� ���� �� ��ǥ�� �ǹ̰� �ְ�����, �� ���������� �������� ����, �ϴ�, ���ϴ����θ� �̵��ϹǷ�, �Ʒ��� ���̳� ���� �� ��ǥ�� ȸ�� ���¸� ������ ������ �ɵ� �ϴ�!

�������� ������ ���� ��ǥ�� ���� �������� ������ �˰� �־�� �� �� �ϴ�!

���� �� ȸ�� ���¿� ���� ������ ������ ��ġ�� ť�� Ǫ���ϸ� bfs�� �����ϸ� �� �� �ϴ�!

�� ������ �湮 ǥ�ø� �ƿ� ���� �ʾƾ� �´�!

=> �밢�� �̵��� ���� �̵����� �ؾ��� ��θ� ���� ���ƹ������� �ֱ� �����̴�!

*/

enum laidState {
	HORIZONTAL,
	VERTICAL,
	DIAGONAL
};

int N;

bool map[18][18];

int solution() {
	int num_of_route = 0;

	// 0, 1: ���� ��ġ�� ��ǥ
	// 2: ���� �������� ����
	// 0
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ 1, 2, HORIZONTAL });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_laidState = bfs_queue.front()[2];
		bfs_queue.pop();

		if (cur_i == N && cur_j == N) {
			num_of_route++;
		}

		// 1. ���η� �������� ���
		if (cur_laidState == HORIZONTAL) {
			// 1) ���� �̵�
			if (map[cur_i][cur_j + 1] == 0) {
				bfs_queue.push({ cur_i, cur_j + 1, HORIZONTAL });
			}
			// 2) ���ϴ� �̵�
			if (map[cur_i + 1][cur_j + 1] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j + 1, DIAGONAL });
			}
		}		
		// 2. ���η� �������� ���
		if (cur_laidState == VERTICAL) {
			// 1) �ϴ��̵� �̵�
			if (map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j, VERTICAL });
			}
			// 2) ���ϴ� �̵�
			if (map[cur_i + 1][cur_j + 1] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j + 1, DIAGONAL });
			}
		}		
		// 3. �밢������ �������� ���
		if (cur_laidState == DIAGONAL) {
			// 1) ���� �̵�
			if (map[cur_i][cur_j + 1] == 0) {
				bfs_queue.push({ cur_i, cur_j + 1, HORIZONTAL });
			}
			// 2) �ϴ� �̵�
			if (map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j, VERTICAL });
			}
			// 3) ���ϴ� �̵�
			if (map[cur_i + 1][cur_j + 1] == 0 && map[cur_i][cur_j + 1] == 0 && map[cur_i + 1][cur_j] == 0) {
				bfs_queue.push({ cur_i + 1, cur_j + 1, DIAGONAL });
			}
		}
	}

	return num_of_route;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i <= N + 1;i++) {
		
		for (int j = 0;j <= N + 1;j++) {
			// �ܺ� ��� ������ֱ�
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				map[i][j] = 1;
			}
			else {
				cin >> map[i][j];
			}
		}
	}

	cout << solution();
}