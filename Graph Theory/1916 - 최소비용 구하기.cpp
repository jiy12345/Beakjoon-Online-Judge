#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int INF = 100000 * 1000;

int V, E;

vector<pair<int, int>> V_state[1001];

int min_distance[1001];

int solution(int startNode, int endNode) {
	// 자신 노드로의 이동은 0
	min_distance[startNode] = 0;

	// top을 최소값으로 유지하는 priority queue(min heap)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push(make_pair(0, startNode));

	while (!pq.empty()) {
		// 현재 노드까지의 최소 거리
		int cur_distance = pq.top().first;
		// 현재 방문한 노드
		int cur_node = pq.top().second;

		pq.pop();

		// 최단거리가 아닐 경우 스킵
		if (min_distance[cur_node] < cur_distance) continue;
		for (int i = 0; i < V_state[cur_node].size(); i++) {
			// 현재 노드를 거쳐서 다음 노드로 가는 비용
			int next_distance = cur_distance + V_state[cur_node][i].first;
			// 다음 방문할 노드
			int next_node = V_state[cur_node][i].second;

			if (next_distance < min_distance[next_node]) {
				min_distance[next_node] = next_distance;
				pq.push(make_pair(next_distance, next_node));
			}
		}
	}
	
	return min_distance[endNode];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startNode, endNode;

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int node1;
		int node2;
		int weight;

		cin >> node1 >> node2 >> weight;

		V_state[node1].push_back({ weight, node2 });
	}

	cin >> startNode >> endNode;

	for (int i = 1; i <= V; i++) {
		min_distance[i] = INF;
	}

	cout << solution(startNode, endNode);
}
