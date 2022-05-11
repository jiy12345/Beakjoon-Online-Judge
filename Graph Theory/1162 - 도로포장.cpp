#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

#define MAX 10001
int N, M;
int K;

vector<pair<int, int>> graph[MAX];

long long distFromStart[MAX][21];

void dijkstra(int start_node) {
	priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> dijkstra_queue;

	dijkstra_queue.push({ 0, 0, start_node });
	distFromStart[start_node][0] = 0;

	while (!dijkstra_queue.empty()) {
		long long cur_dist = dijkstra_queue.top()[0];
		long long cur_pavedRoad = dijkstra_queue.top()[1];
		long long cur_node = dijkstra_queue.top()[2];
		dijkstra_queue.pop();

		if (cur_dist > distFromStart[cur_node][cur_pavedRoad]) continue;

		for (pair<int, int> next_info : graph[cur_node]) {
			long long next_dist = next_info.first;
			long long next_node = next_info.second;

			// 다음 도시까지 포장하지 않을 경우
			if (cur_dist + next_dist < distFromStart[next_node][cur_pavedRoad]) {
				distFromStart[next_node][cur_pavedRoad] = cur_dist + next_dist;
				dijkstra_queue.push({ distFromStart[next_node][cur_pavedRoad], cur_pavedRoad, next_node });
			}

			// 이미 포장횟수를 다 사용하였을 경우 포장은 체크할 필요가 없음
			if(cur_pavedRoad == K) continue;

			// 다음 도시까지 포장할 경우
			if (cur_dist < distFromStart[next_node][cur_pavedRoad + 1]) {
				distFromStart[next_node][cur_pavedRoad + 1] = cur_dist;
				dijkstra_queue.push({ distFromStart[next_node][cur_pavedRoad + 1], cur_pavedRoad + 1, next_node });
			}

		}
	}
}

long long solution() {
	long long answer = INT64_MAX;
	
	fill(&distFromStart[0][0], &distFromStart[MAX - 1][21], INT64_MAX);

	dijkstra(1);

	for (int i = 0; i <= K; i++) {
		answer = min(answer, distFromStart[N][i]);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	int a, b, c;
	for (int j = 0; j < M; j++) {
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	cout << solution();

	return 0;
}
