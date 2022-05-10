#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 5001
#define INF 5001 * 100

int n, m;
int s, t;

vector<pair<int, int>> graph[MAX];

int distFromStart[MAX];

void dijkstra(int start_node) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_queue;

	dijkstra_queue.push({ 0, start_node });
	distFromStart[start_node] = 0;

	while (!dijkstra_queue.empty()) {
		int cur_dist = dijkstra_queue.top().first;
		int cur_node = dijkstra_queue.top().second;
		dijkstra_queue.pop();

		if (cur_dist > distFromStart[cur_node]) continue;

		for (pair<int, int> next_info : graph[cur_node]) {
			int next_dist = next_info.first;
			int next_node = next_info.second;

			if (cur_dist + next_dist < distFromStart[next_node]) {
				distFromStart[next_node] = cur_dist + next_dist;
				dijkstra_queue.push({ distFromStart[next_node], next_node });
			}
		}
	}
}

int solution() {
	fill(&distFromStart[0], &distFromStart[n + 1], INF);

	dijkstra(s);

	return distFromStart[t];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int a, b, c;
	for (int j = 0; j < m; j++) {
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	cin >> s >> t;

	cout << solution();

	return 0;
}
