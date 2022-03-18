#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
/*
1. 문제 분석
- 변수
N: 역의 개수

 - 변수 제한 사항
N: 3 ~ 3,000

임의의 두 역 사이에 경로가 항상 존재하는 노선만 입력으로 주어진다!

- 문제 상황
 그래프가 주어졌을 때, 각 노드와 사이클 사이의 거리를 구하여라.

 문제에 딱히 언급되어있진 않지만 사이클은 한개만 존재해야 할 듯 하다.

2. 풀이 계획
 일단 그래프를 입력 받는 것은 당연히 연결 리스트 형태로 받아야 할 듯 하다.

 왜냐하면 순환선이 생기려면 간선의 개수가 상당히 적어야 하므로

 일단 순환선을 구한 후, 순환선으로부터의 거리를 구하는 순으로 하면 될 듯 하다.

 1. 순환선을 구한다.

 2. 순환선에 포함되는 노드들의 거리는 모두 0으로 초기화한다.

 3. 순환선간의 간선은 삭제한다.

 4. 순환선에 포함되는 모든 노드로부터 bfs를 진행하여, 각 노드까지의 거리를 구한다.

3. 계획 검증


*/

#define MAX 3001
using namespace std;

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
			// 부모가 아닌 다른 방문했던 노드(역간선)이면 사이클임
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
	
	findCycle(1);
	
	bfs();

	for (int i = 1; i <= N; i++) 
		cout << dist[i] << ' ';

	return 0;
}
