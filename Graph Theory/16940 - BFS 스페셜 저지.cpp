#include<iostream>
#include<queue>
#include<set>
using namespace std;

/*
1. 문제 분석
- 변수
N: 정점의 개수


- 변수 제한 사항
N: 2 ~ 100,000
트리 정보가 주어질 때는 1부터 N까지의 정점이 1번씩 등장한다.

- 문제 상황
 트리의 정보가 주어지고, BFS의 방문 순서가 주어질 때,
 해당 방문 순서가 BFS로 가능한 방문 순서인지 체크하라

2. 풀이 계획

 BFS상에서 깊이가 같은 노드끼리는 방문 순서가 바뀔 수 있다. 

 따라서 루트 기준으로 각 노드의 깊이를 기록해놓고, 순서대로 체크하면서 끝까지 비내림 차순을 이룬다면 나올 수 있는 수열
 그렇지 않다면 나올 수 없는 수열로 판단하면 될 듯 하다.
 
 => 이렇게만 한다면 어떤 부모 노드가 나온 후 다음 나오는 노드들이 다른 부모의 자식 노드들일 경우를 체크하지 못한다.
 따라서 하나의 부모가 등장하였을 때, 그부모의 자식들이 먼저 등장하였는지도 체크하여야 한다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


int N;
vector<int> graph[100001];
int visitOrder[100001];
bool isVisited[100001];

int bfs() {
	if (visitOrder[0] != 1) {
		return 0;
	}

	queue<int> bfs_queue;


	bfs_queue.push(1);
	isVisited[1] = true;


	set<int> visitable;
	int idx = 1; // 경로에서 가능한 후보 노드군의 시작 인덱스
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		int sz = 0;
		// 현재 노드로부터 방문 가능한 모든 노드에 대해
		for (int next : graph[cur_node]) {
			// 아직 방문하지 않았을 경우
			if (isVisited[next] == false) {
				// 방문 가능한 후보군에 추가
				visitable.insert(next);
				isVisited[next] = true;
				sz++;
			}
		}

		for (int i = idx; i < idx + sz; i++) {
			// 후보군에 다음 순서의 노드가 없을 경우 만들 수 없는 것
			if (visitable.count(visitOrder[i]) == 0) {
				return 0;
			} // 다음 순서의 노드가 있을 경우 노드 푸시
			else bfs_queue.push(visitOrder[i]);
		}
		idx += sz;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 0; i < N; i++) {
		cin >> visitOrder[i];
	}

	cout << bfs();

	return 0;
}