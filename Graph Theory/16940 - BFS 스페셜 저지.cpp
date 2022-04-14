#include<iostream>
#include<queue>
#include<set>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����


- ���� ���� ����
N: 2 ~ 100,000
Ʈ�� ������ �־��� ���� 1���� N������ ������ 1���� �����Ѵ�.

- ���� ��Ȳ
 Ʈ���� ������ �־�����, BFS�� �湮 ������ �־��� ��,
 �ش� �湮 ������ BFS�� ������ �湮 �������� üũ�϶�

2. Ǯ�� ��ȹ

 BFS�󿡼� ���̰� ���� ��峢���� �湮 ������ �ٲ� �� �ִ�. 

 ���� ��Ʈ �������� �� ����� ���̸� ����س���, ������� üũ�ϸ鼭 ������ �񳻸� ������ �̷�ٸ� ���� �� �ִ� ����
 �׷��� �ʴٸ� ���� �� ���� ������ �Ǵ��ϸ� �� �� �ϴ�.
 
 => �̷��Ը� �Ѵٸ� � �θ� ��尡 ���� �� ���� ������ ������ �ٸ� �θ��� �ڽ� ������ ��츦 üũ���� ���Ѵ�.
 ���� �ϳ��� �θ� �����Ͽ��� ��, �׺θ��� �ڽĵ��� ���� �����Ͽ������� üũ�Ͽ��� �Ѵ�!

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/


int N;
vector<int> graph[100001];
int visitOrder[100001];
bool isVisited[100001];

int bfs() {
	if (visitOrder[0] != 1) {
		return 0;
	}

	queue<int> bfs_queue;


	bfs_queue.push(1);
	isVisited[1] = true;


	set<int> visitable;
	int idx = 1; // ��ο��� ������ �ĺ� ��屺�� ���� �ε���
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		int sz = 0;
		// ���� ���κ��� �湮 ������ ��� ��忡 ����
		for (int next : graph[cur_node]) {
			// ���� �湮���� �ʾ��� ���
			if (isVisited[next] == false) {
				// �湮 ������ �ĺ����� �߰�
				visitable.insert(next);
				isVisited[next] = true;
				sz++;
			}
		}

		for (int i = idx; i < idx + sz; i++) {
			// �ĺ����� ���� ������ ��尡 ���� ��� ���� �� ���� ��
			if (visitable.count(visitOrder[i]) == 0) {
				return 0;
			} // ���� ������ ��尡 ���� ��� ��� Ǫ��
			else bfs_queue.push(visitOrder[i]);
		}
		idx += sz;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 0; i < N; i++) {
		cin >> visitOrder[i];
	}

	cout << bfs();

	return 0;
}