#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
n: 정점의 개수
m: 간선

s: 출발점
t: 도착점

a, b, c: a와 B 사이의 간선은 c의 가중치를 가진다.

- 변수 제한 사항
n: 2 ~ 5,000
m: 1 ~ 100,000

c: 1 ~ 100

- 문제 상황
s와 t가 연결되는 시점의 간선의 가중치 합의 최솟값을 출력하시오,


2. 풀이 계획
s와 t가 연결되는 시점의 간선의 가중치 합의 최솟값은 어차피 s와 t사이의 최단 거리이다. 따라서 다익스트라를 진행하여 s부터 t까지의 거리를 구하면 될 듯 하다.

3. 계획 검증
*/

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
