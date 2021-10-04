#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ ����
M: ������ ����
V: Ž���� ������ ����

- ���� ���� ����
N: 1~1,000
M: 1~10,000
�� ���� ���̿� �������� ������ ���� �� ����!

- ���� ��Ȳ
�Է����� ���� �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����Ѵ�!

2. Ǯ�� ��ȹ
�ϴ� �� ���� ���̿� �������� ������ ���� �� �����Ƿ�, int�� 1000 x 1000 ������ ����� ������ ������ ���Ѵ�!

������ �Լ��� �����Ͽ� dfs

3. ��ȹ ����


*/
int N, M;

int num_of_link_dfs[1001][1001] = { {0,}, }; // �� �������� ������ ���� ǥ���ϴ� 
int num_of_link_bfs[1001][1001] = { {0,}, }; // �� �������� ������ ���� ǥ���ϴ� 

bool node_visited_dfs[1001] = { false, };
bool node_visited_bfs[1001] = { false, };


void DFS(int cur_node) {
	node_visited_dfs[cur_node] = true;
	cout << cur_node <<" ";
	// ���������� ���� ���� ���̻� ������ ��尡 ������ �����!
	for (int i = 1; i <= N;i++) {
		if (num_of_link_dfs[cur_node][i] != 0 && node_visited_dfs[i] == false) {
			num_of_link_dfs[cur_node][i]--;
			num_of_link_dfs[i][cur_node]--;

			DFS(i);
		}
	}
}

void BFS(int start_node) {
	queue<int> bfs_queue;
	bfs_queue.push(start_node);
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();
		node_visited_bfs[cur_node] = true;
		cout << cur_node << " ";

		for (int i = 1; i <= N; i++) {
			if (num_of_link_bfs[cur_node][i] != 0 && node_visited_bfs[i] == false) {
				num_of_link_bfs[cur_node][i]--;
				num_of_link_bfs[i][cur_node]--;
				bfs_queue.push(i);
			}
		}
	}
}

int main() {
	int V;

	cin >> N >> M >> V;

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		num_of_link_dfs[start][end]++;
		num_of_link_dfs[end][start]++;
		num_of_link_bfs[start][end]++;
		num_of_link_bfs[end][start]++;
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}