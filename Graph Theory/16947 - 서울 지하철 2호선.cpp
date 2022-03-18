#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
/*
1. ���� �м�
- ����
N: ���� ����

 - ���� ���� ����
N: 3 ~ 3,000

������ �� �� ���̿� ��ΰ� �׻� �����ϴ� �뼱�� �Է����� �־�����!

- ���� ��Ȳ
 �׷����� �־����� ��, �� ���� ����Ŭ ������ �Ÿ��� ���Ͽ���.

 ������ ���� ��޵Ǿ����� ������ ����Ŭ�� �Ѱ��� �����ؾ� �� �� �ϴ�.

2. Ǯ�� ��ȹ
 �ϴ� �׷����� �Է� �޴� ���� �翬�� ���� ����Ʈ ���·� �޾ƾ� �� �� �ϴ�.

 �ֳ��ϸ� ��ȯ���� ������� ������ ������ ����� ����� �ϹǷ�

 �ϴ� ��ȯ���� ���� ��, ��ȯ�����κ����� �Ÿ��� ���ϴ� ������ �ϸ� �� �� �ϴ�.

 1. ��ȯ���� ���Ѵ�.

 2. ��ȯ���� ���ԵǴ� ������ �Ÿ��� ��� 0���� �ʱ�ȭ�Ѵ�.

 3. ��ȯ������ ������ �����Ѵ�.

 4. ��ȯ���� ���ԵǴ� ��� ���κ��� bfs�� �����Ͽ�, �� �������� �Ÿ��� ���Ѵ�.

3. ��ȹ ����


*/

#define MAX 3001
using namespace std;
int N;
bool isCycle[MAX]; // ����Ŭ���� ���� �Ǵ�
vector<int> graph[MAX]; // �׷���
bool visited[MAX];
int pre[MAX];// ���� ����� ���� ��带 ǥ���ϱ� ���� �迭
bool hasCycle; // ����Ŭ�� ã�Ҵ��� ���� ������ ���� ����
int dist[MAX];

void bfs() {
	queue<pair<int, int>> bfs_queue;
	for (int i = 1; i <= N; i++) {
		if (isCycle[i]) {
			visited[i] = true;
			//       ���� ��� / ����
			bfs_queue.push({ i,0 });
		}
	}
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		visited[cur_node] = true;

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next = graph[cur_node][i];
			if (visited[next]) continue;
			dist[next] = cur_depth + 1;
			bfs_queue.push({ next,cur_depth + 1 });
		}
	}
}

void findCycle(int cur) {
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		// ����Ŭ�� ã�Ҵٸ� ����
		if (hasCycle) return;

		int next = graph[cur][i];

		// �̹� �湮�� ����� ��
		if (visited[next]) {
			// �θ� �ƴ� �ٸ� �湮�ߴ� ���(������)�̸� ����Ŭ��
			if (next != pre[cur]) {
				
				isCycle[cur] = true;
				hasCycle = true;
				while (cur != next) {
					isCycle[pre[cur]] = true;
					cur = pre[cur];
				}
				return;
			}

		}
		else { // ���� �湮���� ���� �����
			pre[next] = cur;
			findCycle(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	
	findCycle(1);
	
	memset(visited, false, MAX);
	
	bfs();

	for (int i = 1; i <= N; i++) 
		cout << dist[i] << ' ';

	return 0;
}