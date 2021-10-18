#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
 N: �������� ������ ��Ÿ�� ����

- ���� ���� ����
 N: 1~100,000

- ���� ��Ȳ
 �־��� �ڿ��� N�� ���������� ������ ǥ���� ��, �� ���� �ּ� ������ ���϶�.

2. Ǯ�� ��ȹ
 BFS���Ͽ� �湮�� ���� �ٽ� �湮���� �ʵ��� �ϸ� �ɵ��ϴ�!

3. ��ȹ ����

*/

bool is_visited[100001] = { false };

int N;

int solution() {
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front()[0];
		int cur_depth = bfs_queue.front()[1];

		bfs_queue.pop();
		
		if (cur_num == 0) {
			return cur_depth;
		}

		int next_num;
		int k = 1;

		while (k * k <= cur_num) {
			next_num = cur_num - k * k;
			if (is_visited[next_num] == false) {
				is_visited[next_num] = true;
				bfs_queue.push({ next_num, cur_depth + 1 });
			}
			k++;
		}	
	}
}


int main() {
	cin >> N;

	cout << solution();
}