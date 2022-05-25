#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
            
#define INF 987654321
#define MAX 5001

struct info {
	int node, dist;
};
struct cmp {
	bool operator()(info& a, info& b) {
		return a.dist > b.dist;
	}
};

info tmp;
int V, E, P;

int dist[MAX];
vector<info> graph[MAX];

int dijkstra(int start, int dest) {
	for (int i = 1; i <= V; i++)
		dist[i] = INF;

	int answer = 0;
	dist[start] = 0;
	priority_queue<info, vector<info>, cmp> pq;
	tmp.node = start;
	tmp.dist = 0;
	pq.push(tmp);

	while (!pq.empty()) {
		int cur_node = pq.top().node;
		int cur_dist = pq.top().dist;
		pq.pop();
		if (cur_node == dest) {
			answer = cur_dist;
			break;
		}
		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].node;
			int next_dist = graph[cur_node][i].dist;
			if (dist[next_node] > dist[cur_node] + next_dist) {
				dist[next_node] = dist[cur_node] + next_dist;
				tmp.node = next_node;
				tmp.dist = dist[cur_node] + next_dist;
				pq.push(tmp);
			}
		}
	}
	return answer;
}

string solution() {
	int result1 = dijkstra(1, V);
	int result2 = dijkstra(1, P) + dijkstra(P, V);
	return (result1 >= result2) ? "SAVE HIM" : "GOOD BYE";
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> P;
	for (int i = 0; i < E; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		tmp.dist = c;
		tmp.node = a;
		graph[b].push_back(tmp);
		tmp.node = b;
		graph[a].push_back(tmp);
	}

	cout << solution();

	return 0;
}