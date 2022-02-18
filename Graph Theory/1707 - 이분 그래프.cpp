#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
K: �׽�Ʈ ���̽��� ��
V: ������ ����
E: ������ ����

- ���� ���� ����
K: 2 ~ 5
V: 1 ~ 20,000
E: 1 ~ 200,000

- ���� ��Ȳ
 �׷����� ������ �� �������� �з��Ͽ�, �� ���տ� ���� ���������� ���� �������� �ʵ��� ������ �� �ִ� �׷����� �̺� �׷������ �Ѵ�.

 �׷����� �Է����� �־����� ��, �� �׷����� �̺� �׷������� �ƴ��� �Ǻ��϶�

2. Ǯ�� ��ȹ

� �̺� �׷������ ���� �׷����� ��ȯ(cycle) ��ΰ� �������� �ʾƾ� �Ѵٴ� ���� ���Ѵ�.

���� ��ȯ����� ���缺�� üũ�ϸ� �� �� �ϴ�!

1. ���� ����Ʈ�� ���·� �׷����� �Է� �޴´�.
2. ��� ��忡�� �����ϴ� ��θ� üũ�ϵ�, �ѹ� ��� Ž������ üũ�� ���� ���������� �ٽ� üũ���� �ʵ����Ѵ�.
3. ��ȯ ��θ� �߰��Ͽ��ٸ� NO�� ����ϰ�, ��� ��带 Ž���ϴ� ���� ��ȯ ��θ� �߰����� ���Ͽ��ٸ�

��ȯ ��θ� üũ�ϱ� ���ؼ��� ���� �ܰ谡 ���� ��ġ���� ���µ� ���Ŀ� ����� ����� �˾ƾ� �Ѵ�!

=> �� ����� ������ �� ���� ��尡 �ƴϸ鼭 �湮�� ��� ��Ͽ� �ִ� ���� ���� ��ΰ� ���� ��쿡 NO�� ����ϵ��� �ϸ� �� �� �ϴ�!

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

enum Color{NONE, RED, BLUE};

// ���� ���� �������� ȣ���� �ǹǷ� �ܺο��� ������ ���� ������ ���� ȣ���� �����ؾ�!
bool isCycle(int startNode, vector<bool> &isVisited, vector<int>* graph) {
	vector<int>Color(isVisited.size());

	queue <pair<int, int>> bfs_queue;

	bfs_queue.push(make_pair(startNode, 0));
	Color[startNode] = RED;

	while (!bfs_queue.empty()) {
		int curNode = bfs_queue.front().first;
		int curDepth = bfs_queue.front().second;
		int nextDepth = curDepth + 1;
		bfs_queue.pop();

		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i];

			if (Color[curNode] == Color[nextNode]) {
				return true;
			}

			if (isVisited[nextNode] == false) {
				isVisited[nextNode] = true;

				Color[nextNode] = (nextDepth % 2 == 0) ? RED : BLUE;

				bfs_queue.push(make_pair(nextNode, nextDepth));
			}
		}
	}

	return false;
}

bool solution(int V, vector<int>* graph) {
	vector<bool> isVisited(V + 1);

	for (int i = 0; i < V; i++) {
		cout << "isVisited[" << i << "]: " << isVisited[i] << endl;
		if (isVisited[i] == false) {
			isVisited[i] = true;

			if (isCycle(i, isVisited, graph)) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		vector<int> graph[20001];
		int V, E;
		cin >> V >> E;

		for (int j = 0; j < E; j++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		cout << ((solution(V, graph)) ? "YES" : "NO") << '\n';
	}

	return 0;
}