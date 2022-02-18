#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum Color{NONE, RED, BLUE};

// 벡터 또한 값에의한 호출이 되므로 외부에의 적용을 위해 참조에 의한 호출을 진행해야!
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
