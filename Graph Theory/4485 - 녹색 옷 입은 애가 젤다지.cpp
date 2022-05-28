#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 987654321

int di[4] = { 1,0,-1,0 };
int dj[4] = { 0,1,0,-1 };
int N;
int cave[125][125];
vector<pair<int, int>> node[15625];
vector<int> dist;

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,dist[0] });

	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_dist = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[cur_node].size(); i++) {
			int next_node = node[cur_node][i].first;
			int next_dist = cur_dist + node[cur_node][i].second;
			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				pq.push({ next_node,next_dist });
			}
		}
	}
}

void graph_construction() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int next_i = i + di[k];
				int next_j = j + dj[k];
				if (isInRange(next_i, next_j)) {
					int start = N * i + j;
					int end = N * next_i + next_j;
					int cost = cave[next_i][next_j];
					node[start].push_back({ end,cost });
				}
			}
		}
	}
}

int main() {
	int cnt = 1;
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cave[i][j];
			}
		}

		graph_construction();

		dist.assign(N * N, INF);
		dist[0] = cave[0][0];
		dijkstra();

		cout << "Problem " << cnt++ << ": " << dist[N * N - 1] << '\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				node[N * i + j].clear();
			}
		}
	}

	return 0;
}