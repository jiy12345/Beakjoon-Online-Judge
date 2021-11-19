#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ ����

- ���� ���� ����
N: 1~100

- ���� ��Ȳ
 ����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i,j)�� ���� i���� j�� ���� ��ΰ� �ִ��� �������� ������� �������� ����Ѵ�!

2. Ǯ�� ��ȹ
��� 1�� �κ�(��)�� ���� BFS�� �����ϸ�,

3. ��ȹ ����


*/

int N;

int graph[100][100];

int answer[100][100];


void bfs(int cur_graph[100][100], int start_node) {
	queue<int> bfs_queue;
	// �� ��ġ���� ����� ��� ��� Ǫ��
	for (int i = 0;i < N;i++) {
		// �̹� Ž���� ��� ǥ��
		if (cur_graph[start_node][i] == 1) {
			// ��ΰ� �ִٴ� ǥ��
			answer[start_node][i] = 1;
			// �̹� Ž���� ������� ǥ��
			cur_graph[start_node][i] = 0;
			// ��� ť�� Ǫ��
			bfs_queue.push(i);
		}
	}

	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		// �� ��ġ���� ����� ��� ��� Ǫ��
		for (int i = 0;i < N;i++) {
			// �̹� Ž���� ��� ǥ��
			if (cur_graph[cur_node][i] == 1) {
				// ��ΰ� �ִٴ� ǥ��
				answer[start_node][i] = 1;
				// �̹� Ž���� ������� ǥ��
				cur_graph[cur_node][i] = 0;
				// ��� ť�� Ǫ��
				bfs_queue.push(i);
			}
		}
	}
}

void solution() {
	// ������ ��� ��忡 ���ؼ� üũ
	for (int i = 0;i < N;i++) {
		int cur_graph[100][100];
		copy(&graph[0][0], &graph[0][0] + 100 * 100, &cur_graph[0][0]);
		bfs(cur_graph, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> graph[i][j];
		}
	}

	solution();

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}