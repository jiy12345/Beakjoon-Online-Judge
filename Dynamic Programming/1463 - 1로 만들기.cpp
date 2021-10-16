#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
 N: ������ ������ ����

- ���� ���� ����
 N: 1~1,000,000

- ���� ��Ȳ
���� X�� ����� �� �ִ� ������ ������ ���� 3������� ���� ��,

1. X�� 3���� ������ ��������, 3���� ������.
2. X�� 2�� ������ ��������, 2�� ������.
3. 1�� ����.

���� ������� ����Ͽ� X�� 1�� ���� �� �ִ� ���� Ƚ���� �ּڰ��� ���Ͽ���.

2. Ǯ�� ��ȹ
 BFS���Ͽ� �湮�� ���� �ٽ� �湮���� �ʵ��� �ϸ� �ɵ��ϴ�!

3. ��ȹ ����

*/

bool is_visited[1000001] = { false };

int N;

int solution() {
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		vector<int> temp = bfs_queue.front();
		bfs_queue.pop();
		int cur_N = temp[0];
		int cur_depth = temp[1];

		if (cur_N == 1) {
			return cur_depth;
		}

		int next_N;
		// 3���� ������ ������ ���
		if (cur_N % 3 == 0) {
			next_N = cur_N / 3;
			// �̹� ���� ���� �ƴ� ��쿡�� ���
			if (is_visited[next_N] == false) {
				is_visited[next_N] = true;
				bfs_queue.push({ next_N, cur_depth + 1 });
			}
		}		
		// 2�� ������ ������ ���
		if (cur_N % 2 == 0) {
			next_N = cur_N / 2;
			// �̹� ���� ���� �ƴ� ��쿡�� ���
			if (is_visited[next_N] == false) {
				is_visited[next_N] = true;
				bfs_queue.push({ next_N, cur_depth + 1 });
			}
		}
		next_N = cur_N - 1;
		// �̹� ���� ���� �ƴ� ��쿡�� ���
		if (is_visited[next_N] == false) {
			is_visited[next_N] = true;
			bfs_queue.push({ next_N, cur_depth + 1 });
		}
	}
	return 0;
}


int main() {
	cin >> N;

	cout << solution();
}