#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 V: 정점의 개수
 E: 간선의 개수
 W: 간선의 가중치(비용)
 K: 시작 정점의 번호

- 변수 제한 사항
 V: 1~20,000
 E: 1~300,000
 W: 1~10

 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음

- 문제 상황
 정점과 간선의 연결 상태와 시작 정점이 주어질 때, 


2. 풀이 계획
 전형적인 다익스트라 문제이다!

 그런데 정점의 개수가 20000개이므로, 정점의 개수로 2차원 배열을 만들면 20,000*20,000*4=1.6기가가 되어 매우 커지게 된다.

 따라서 linked 

*/

#define INF 200000;

int V, E;


vector<pair<int, int>> V_state[20001];

int min_distance[20001];

void solution(int startNode) {
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
		for (int i = 0;i < V_state[cur_node].size();i++) {
			// 현재 노드를 거쳐서 다음 노드로 가는 비용
			int next_distance = cur_distance + V_state[cur_node][i].first;
			// 다음 방문할 노드
			int next_node = V_state[cur_node][i].second;
			
			if (next_distance < min_distance[next_node]) {
				min_distance[next_node] = next_distance;
				pq.push(make_pair(next_distance, next_node ));
			}
		}
	}

	for (int i = 1;i <= V;i++) {
		if (min_distance[i] == 200000) {
			cout << "INF\n";
		}
		else {
			cout << min_distance[i] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startNode;

	cin >> V >> E;

	cin >> startNode;

	for (int i = 0;i < E ;i++) {
		int node1;
		int node2;
		int weight;

		cin >> node1 >> node2 >> weight;

		V_state[node1].push_back({ weight, node2 });
	}

	for (int i = 1; i <= V;i++) {
		min_distance[i] = INF;
	}

	solution(startNode);
}