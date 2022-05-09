#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
T: 테스트 케이스의 개수

n: 교차로(노드)의 개수
m: 도로(간선)의 개수
t: 목적지 후보의 개수

s: 출발지
g, h: g, h사이의 길은 반드시 지나가야 함

a, b, d: a와 b 사이의 길이 d길이이다.


- 변수 제한 사항
 T: 1 ~ 100
 
 n: 2 ~ 2,000
 m: 1 ~ 50,000
 t: 1 ~ 100

 g != h
g와 h사이에는 도로가 반드시 있다.
또한 이 도로는 목적지 후보들 중 적어도 1개로 향하는 최단경로의 일부이다.

d: 1 ~ 1,000

교차로 사이에는 도로가 1개 이상 존재하지 않는다!

- 문제 상황
테스트 케이스마다 입력에서 주어진 목적지 후보들 중 불가능한 경우들을 제외한 목적지들을 공백으로 분리시킨 오름차순 정수들로 출력한다.


2. 풀이 계획

출발점에서 목적지로 갈수 있는 경우는 다음과 같다.

출발점 => g => h => 도착점
출발점 => h => g => 도착점

위의 경우들에 대해 경로 수의 합이 INF 미만인 것들은 목적지가 될 수 있는 것들이라 볼 수 있다!


3. 계획 검증
*/

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
