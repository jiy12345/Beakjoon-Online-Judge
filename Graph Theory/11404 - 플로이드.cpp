#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
