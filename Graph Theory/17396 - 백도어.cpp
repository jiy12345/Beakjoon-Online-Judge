#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e10 * 3
#define MAX 100001

int N, M;
bool ward[MAX];
vector<pair<long long, int>> V[MAX];

long long dijkstra() {
	vector<long long> dist(N, INF);

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> dijkstra_queue;
	dijkstra_queue.push({ 0,0 });
	while (!dijkstra_queue.empty()) {
		int cur_node = dijkstra_queue.top().second;
		long long cur_dist = dijkstra_queue.top().first;
		dijkstra_queue.pop();
		if (cur_dist > dist[cur_node]) continue;
		for (int i = 0; i < V[cur_node].size(); i++) {
			int next_node = V[cur_node][i].first;
			long long next_dist = cur_dist + V[cur_node][i].second;
			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				dijkstra_queue.push({ next_dist,next_node });
			}
		}
	}
	if (dist[N - 1] == INF) return -1;
	else return dist[N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t) ward[i] = true;
	}
	ward[N - 1] = false;

	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		if (ward[a] || ward[b]) { continue; }
		V[a].push_back({ b,t });
		V[b].push_back({ a,t });
	}
	
	cout << dijkstra();
	
	return 0;
}