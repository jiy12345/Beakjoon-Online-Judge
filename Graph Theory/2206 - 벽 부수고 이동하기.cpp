#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� ���� ����
M: ���� ���� ����

- ���� ���� ����
N, M: 1~1,000

- ���� ��Ȳ
 �Ѱ��� ���� �μ��� �̵��� �� �ִٰ� �� ��, �ִ� �Ÿ��� ����Ѵ�.

�Ұ����ϴٸ� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ
 1000 * 1000�̸� �Ϲ����� DFS�� �����Ͽ����� �ð��ʰ��� ������ ũ���̴�. ���� BFS�� �����ؾ� �� �� �ϴ�.

 �׷��� BFS�� ������ �� ť�� Ǫ���� �� �湮 ǥ�ø� �Ͽ� �ߺ��湮�� �ȵǱ� �Ѵٸ� ������?

 �ش� ��ġ���� �ִܰŸ���� ������ �� �ֳ�?
  => �ϴ� �մ´ٰ� �����ϱ� ������

  �մ� ���� ǥ�����൵ �湮ǥ�ø� ���� �ع����ٸ� �ش� ��ΰ� ������ ���̻� �� �� ���� ��찡 �Ǿ��� ��쿡�� ��ΰ� �������� ��θ� ã�� ���ϴ� ��찡 �߻��� ���� �ִ�!

  => �׷��ٸ� ���� ������ ��쿡�� �湮 ǥ�ø� �������� �ʴ´ٸ� ���?
  => �׷��� �̷��� �Ѵٸ� 4���� �̵��̱� ������ ����ؼ� �̵��� �ϴ� ��찡 �߻��� �� �ִ�!
*/

int N, M;

int dx[4] = { 0,  0, 1, -1 };
int dy[4] = { 1, -1, 0,  0 };

string map[1000];
// �վ��� ���� ���� �ʾ��� ���� ��θ� ���� ����ϱ� ���� 3�������� ����
int depth[1000][1000][2];

int solution() {
	int answer = -1;

	// ��ǥ, ���� �մ� ��ȸ�� �� ����
	queue<vector<int>> bfs_queue;
	
	bfs_queue.push({ 0,0,1 });

	depth[0][0][1] = 1; // ù ��ġ������ �̵��� 1�� ����

	while (!bfs_queue.empty()) {
		int cur_x = bfs_queue.front()[0];
		int cur_y = bfs_queue.front()[1];
		int block_num = bfs_queue.front()[2];
		bfs_queue.pop();

		cout << "cur_x: " << cur_x << ", cur_y: " << cur_y << endl;;

		if (cur_x == N - 1 && cur_y == M - 1) {
			answer = depth[cur_x][cur_y][block_num];
			break;
		}

		for (int i = 0;i < 4;i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				// �� ������ ��(��)�̰�, ���� ���� �ȶվ�����
				if (map[next_x][next_y] == '1' && block_num == 1) {
					depth[next_x][next_y][block_num - 1] = depth[cur_x][cur_y][block_num] + 1;
					bfs_queue.push({ next_x, next_y, block_num - 1 });
				}
				// �� ���ִ� ���̰�, �湮���� �ʾҴٸ�
				if (map[next_x][next_y] == '0' && depth[next_x][next_y][block_num] == 0) {
					depth[next_x][next_y][block_num] = depth[cur_x][cur_y][block_num] + 1;
					bfs_queue.push({ next_x, next_y, block_num });
				}
			}
		}
	}

	return answer;
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		cin >> map[i];
	}

	cout << solution();
}