#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 2001
#define INF 2000 * 50000

int T;
int n, m, t;
int s, g, h;

vector<pair<int, int>> graph[MAX];

int listOfDestinations[101];

int distFromStart[MAX];
int distFromG[MAX];
int distFromH[MAX];
int distGfromH;

void dijkstra(int start_node, int *distFromStart) {

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
				dijkstra_queue.push({ distFromStart[next_node], next_node});
			}
		}
	}
}

void solution() {
	fill(&distFromStart[0], &distFromStart[n + 1], INF);
	fill(&distFromG[0], &distFromG[n + 1], INF);
	fill(&distFromH[0], &distFromH[n + 1], INF);

	dijkstra(s, distFromStart);
	dijkstra(h, distFromH);
	dijkstra(g, distFromG);

	vector<int> possibleDestList;
	for (int i = 0; i < t; i++) {
		if (distFromStart[g] + distGfromH + distFromH[listOfDestinations[i]] == distFromStart[listOfDestinations[i]])
			possibleDestList.push_back(listOfDestinations[i]);
		else if(distFromStart[h] + distGfromH + distFromG[listOfDestinations[i]] == distFromStart[listOfDestinations[i]])
			possibleDestList.push_back(listOfDestinations[i]);
	}

	sort(possibleDestList.begin(), possibleDestList.end());

	for (int cur_dest : possibleDestList)
		cout << cur_dest << " ";
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		int a, b, d;
		for (int j = 0; j < m; j++) {
			cin >> a >> b >> d;

			graph[a].push_back({ d, b });
			graph[b].push_back({ d, a });

			if ((a == g && b == h) || (a == h && b == g)) distGfromH = d;
		}

		for (int j = 0; j < t; j++)
			cin >> listOfDestinations[j];

		solution();

		for (int j = 1; j <= n; j++) {
			graph[j].clear();
		}
	}

	return 0;
}
