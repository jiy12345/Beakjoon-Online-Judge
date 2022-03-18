#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 3001
using namespace std;
int N;
bool isCycle[MAX]; // 사이클인지 여부 판단
vector<int> graph[MAX]; // 그래프
bool visited[MAX];
int pre[MAX];// 현재 노드의 이전 노드를 표시하기 위한 배열
bool hasCycle; // 사이클을 찾았는지 여부 저장을 위한 변수
int dist[MAX];

void bfs() {
	queue<pair<int, int>> bfs_queue;
	for (int i = 1; i <= N; i++) {
		if (isCycle[i]) {
			visited[i] = true;
			//       현재 노드 / 깊이
			bfs_queue.push({ i,0 });
		}
	}
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		visited[cur_node] = true;

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next = graph[cur_node][i];
			if (visited[next]) continue;
			dist[next] = cur_depth + 1;
			bfs_queue.push({ next,cur_depth + 1 });
		}
	}
}

void findCycle(int cur) {
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		// 사이클을 찾았다면 종료
		if (hasCycle) return;

		int next = graph[cur][i];

		// 이미 방문한 노드일 때
		if (visited[next]) {
			// 부모가 아닌 다른 방문했던 노드(역간선)이면 사이클임
			if (next != pre[cur]) {
				
				isCycle[cur] = true;
				hasCycle = true;
				while (cur != next) {
					isCycle[pre[cur]] = true;
					cur = pre[cur];
				}
				return;
			}

		}
		else { // 아직 방문하지 않은 노드라면
			pre[next] = cur;
			findCycle(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	
	findCycle(1);
	
	memset(visited, false, MAX);
	
	bfs();

	for (int i = 1; i <= N; i++) 
		cout << dist[i] << ' ';

	return 0;
}
