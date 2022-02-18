#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
K: 테스트 케이스의 수
V: 정점의 개수
E: 간선의 개수

- 변수 제한 사항
K: 2 ~ 5
V: 1 ~ 20,000
E: 1 ~ 200,000

- 문제 상황
 그래프의 정점을 두 집합으로 분류하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있는 그래프를 이분 그래프라고 한다.

 그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하라

2. 풀이 계획

어떤 이분 그래프라는 것은 그래프에 순환(cycle) 경로가 존재하지 않아야 한다는 것을 말한다.

따라서 순환경로의 존재성만 체크하면 될 듯 하다!

1. 인접 리스트의 형태로 그래프를 입력 받는다.
2. 모든 노드에서 시작하는 경로를 체크하되, 한번 경로 탐색에서 체크된 노드는 시작점으로 다시 체크되지 않도록한다.
3. 순환 경로를 발견하였다면 NO를 출력하고, 모든 노드를 탐색하는 동안 순환 경로를 발견하지 못하였다면

순환 경로를 체크하기 위해서는 현재 단계가 현재 위치까지 오는데 거쳐온 노드의 목록을 알아야 한다!

=> 이 목록을 저장한 후 이전 노드가 아니면서 방문한 노드 목록에 있는 노드로 가는 경로가 있을 경우에 NO를 출력하도록 하면 될 듯 하다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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