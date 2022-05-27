#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define INF 30000000

int N, M, W;

bool bellman_ford(vector<vector<int>> edges) {
	vector<int> dist(N + 1, INF);

	int s, e, t;
	dist[1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < edges.size(); j++) {
			s = edges[j][0];
			e = edges[j][1];
			t = edges[j][2];
			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}

	for (int j = 0; j < edges.size(); j++) {
		s = edges[j][0];
		e = edges[j][1];
		t = edges[j][2];
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;

	int s, e, t;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M >> W;

		vector<vector<int>> edges;

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		if (bellman_ford(edges)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
