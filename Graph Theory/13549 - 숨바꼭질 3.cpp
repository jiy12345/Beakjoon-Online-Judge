#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
 N: �������� ���� ��ġ
 K ������ ���� ��ġ

- ���� ���� ����
 N: 1~100,000
 K: 1~100,000


- ���� ��Ȳ
�������� �̵� ����� ������ ����.

 �������� ���� ��ġ�� X��� �� ��, 

 1. �ȱ�: 1���� X-1Ȥ�� X+1 ��ġ�� �̵�

 2. �����̵�: 1���� 2*X��ġ�� �̵�

 ������ �������� ��ġ�� �־��� ��, ���� ���� �ð��� �� �� �������� ���� ���� �ð����� ã�� ����� ��������� ã�ƶ�!


2. Ǯ�� ��ȹ

�ϴ� ����ġ�� ���� ���ã�� �����̹Ƿ� �翬�� BFS�� ó���ϸ� �ɵ� �ϰ�,

�������� ���� ��θ� ã���� �ٷ� ���������� ���� �ƴ� �� ���̿� �ִ� �͵� �� ���ϴ� ��ġ�� ������ ��ε��� ������ ����,

���̰� ���� ���̷� �Ѿư��� ��� ���߸� �� �� �ϴ�!

*/

int N, K;

bool is_visited[100001];

void solution() {
	int optimal_time = 100001;
	int num_optimal_route = 0;

	queue<pair<int, int>> bfs_queue;

	// ù ��ġ ����
	bfs_queue.push({ N, 0 });

	is_visited[N] = true;

	while (!bfs_queue.empty()) {
		int X = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();

		// pop�� �� �湮 ǥ��
		is_visited[X] = true;

		if (cur_depth > optimal_time) {
			break;
		}

		if (X == K) {
			optimal_time = cur_depth;
			num_optimal_route++;
		}


		// X - 1
		if ((X - 1 >= 0) && (is_visited[X - 1] == false)) {
			bfs_queue.push({ X - 1, cur_depth + 1 });
		}		

		// X + 1
		if ((X + 1 <= 100000) && (is_visited[X + 1] == false)) {
			bfs_queue.push({ X + 1, cur_depth + 1 });
		}

		// 2 * x
		if ((2 * X  <= 100000) && (is_visited[2 * X] == false)) {
			bfs_queue.push({ 2 * X, cur_depth + 1 });
		}
	}

	cout << optimal_time << '\n';
	cout << num_optimal_route << '\n';
}

int main() {
	cin >> N >> K;

	solution();
}