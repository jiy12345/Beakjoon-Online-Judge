#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1. 문제 분석
- 변수
n: 도시(정점)의 개수
m: 버스(간선)의 개수

- 변수 제한 사항
n: 2~100
m: 1~100,000
비용은 100,000보다 작거나 같은 자연수이다.
시작 도시와 도착 도시가 같은 경우는 없다.
시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

- 문제 상황
n개의 줄에 걸쳐 도시 i에서 j로 가는데 필요한 최소 비용을 출력하라.
만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.



2. 풀이 계획
 영역이 어떻게 되는지 알기 위해서는 한 부분당 한번의 탐색만 있으면 되고, 각각의 이동에 가중치가 없으므로,

방문 표시를 미리하고 탐색을 진행하는 BFS를 통해 풀 수 있는 문제처럼 보인다!

따라서 적록 색약일 때와 아닐때에 대해 각각 모든 아직 방문하지 않은 위치에서의 bfs를 진행하면 될 듯 하다!

3. 계획 검증

*/

int INF = 100001 * 100;

int n, m;

int min_distance[101][101];

void solution() {

	// i: 거쳐가는 도시
	for (int i = 1; i <= n; i++) {
		// j: 출발 도시
		for (int j = 1; j <= n; j++) {
			// k: 도착 도시
			for (int k = 1; k <= n; k++) {
				// 출발 도시와 도착 도시가 다를 때만 계산 진행
				if (j != k) {
					// i번째 도시를 거쳐가는 것이 j에서 k를 바로 가는것보다 가깝다면 갱신
					min_distance[j][k] = min(min_distance[j][k], min_distance[j][i] + min_distance[i][k]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		// j: 출발 도시
		for (int j = 1; j <= n; j++) {
			if (min_distance[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << min_distance[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startNode;

	cin >> n;
	cin >> m;

	fill(&min_distance[0][0], &min_distance [100][101], INF);

	for (int i = 0; i < m; i++) {
		int startCity;
		int endCity;
		int cost;

		cin >> startCity >> endCity >> cost;

		// 현재 값보다 작을때만 갱신
		min_distance[startCity][endCity] = min(min_distance[startCity][endCity], cost);
	}

	solution();
}