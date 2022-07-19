#include<iostream>
#include<queue>
#include<map>
using namespace std;

/*
1. ���� �м�
- ����
A, B: �־����� �� ����


- ���� ���� ����
1,000,000,000


- ���� ��Ȳ
�� �� A, B�� �־�����, ������ ������ ������ ���ٰ� �� ��,

2�� ���Ѵ�.
1�� ���� ���� �����ʿ� �߰��Ѵ�.

A�� B�� �ٲٴµ� �ʿ��� ������ �ּҰ��� ���Ͽ���.
�ٲ� �� ���� ��� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ

1. bfs�� �����ϵ�

�湮 ǥ�ø� bool������ �����ϸ� 1�Ⱑ����Ʈ�� �ʿ��ϴ�. ��� ó���� �� ������?

- ���� 1: ��Ʈ ���� <<�� ���� ����
=> ���� 1�� ����� �׻� ¦���̴�.
- ���� 2: ���� 10�� ���� �� 1 ���ϴ� ������ ���� ����
=> ���� 2�� ����� �׻� Ȧ���̴�.

=> ������ �� ������ ��� ���� Ŀ���� �����̹Ƿ�, B�̻����� ������ �ʿ䰡 ����.



3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/

int A, B;
map<int, int> isVisited;


int bfs() {
	int answer = -1;

	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ 0, B });

	while (!bfs_queue.empty()) {
		int cur_depth		= bfs_queue.front().first;
		long long cur_i		= bfs_queue.front().second;
		bfs_queue.pop();

		if (cur_i <= A) {
			if(cur_i == A) answer = cur_depth + 1;
			break;
		}

		int next_depth = cur_depth + 1;

		// ���� 1. 2�� ������
		if (cur_i % 2 == 0) {
			int next_i = cur_i >> 1;

			bfs_queue.push({ next_depth, next_i });
		}

		if ((cur_i - 1) % 10 == 0) {
			// ���� 2. 10�� ���ϰ� 1 ���ϱ�
			int next_i = (cur_i -1) / 10;
	
			isVisited[next_i]++;
			bfs_queue.push({ next_depth, next_i });
		
		}

	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	cout << bfs();
}