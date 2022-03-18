#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 3001

int N;
bool isCycle[MAX]; // 사이클인지 여부 판단
vector<int> graph[MAX]; // 그래프
bool isVisited[MAX];
int prevNode[MAX];// 현재 노드의 이전 노드를 표시하기 위한 배열
int dist[MAX];

void bfs() {
	vector<bool>isVisited(N + 1, false);

	queue<pair<int, int>> bfs_queue;
	for (int i = 1; i <= N; i++) {
		if (isCycle[i]) {
			isVisited[i] = true;
			//       현재 노드 / 깊이
			bfs_queue.push({ i, 0 });
		}
	}
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		isVisited[cur_node] = true;

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int nextNode = graph[cur_node][i];
			if (isVisited[nextNode]) continue;
			dist[nextNode] = cur_depth + 1;
			bfs_queue.push({ nextNode,cur_depth + 1 });
		}
	}
}

bool findCycle(int curNode) {
	isVisited[curNode] = true;
	for (int i = 0; i < graph[curNode].size(); i++) {

		int nextNode = graph[curNode][i];

		// 이미 방문한 노드일 때
		if (isVisited[nextNode]) {
			if (nextNode != prevNode[curNode]) {
				isCycle[curNode] = true;
				while (curNode != nextNode) {
					isCycle[prevNode[curNode]] = true;
					curNode = prevNode[curNode];
				}
				return true;
			}

		}
		else { // 아직 방문하지 않은 노드라면
			prevNode[nextNode] = curNode;
			if (findCycle(nextNode)) return true;
		}
	}

	return false;
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
	
	// 아무 노드에서나 
	findCycle(1);
	
	bfs();

	for (int i = 1; i <= N; i++) 
		cout << dist[i] << ' ';

	return 0;
}
