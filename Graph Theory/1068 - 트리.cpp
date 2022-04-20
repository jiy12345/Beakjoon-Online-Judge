#include<iostream>
#include<vector>
using namespace std;


/*
1. 문제 분석
- 변수
N: 트리 노드의 개수

 - 변수 제한 사항
N: 1 ~ 50

- 문제 상황
 트리의 상태와 지울 노드가 주어졌을 때 리프 노드의 개수를 구하여라

2. 풀이 계획


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define MAX 50

int N, nodeToDelete;
vector<int> graph[MAX];
int numLeafNode;

void dfs(int nodeNum) {
	int numChildNode = 0;

	for (int nextNode : graph[nodeNum]) {
		// 삭제된 노드일 경우 그 방향으로 탐색하지 않음
		if (nextNode != nodeToDelete) {
			dfs(nextNode);
			numChildNode++;
		}
	}

	if (numChildNode == 0) numLeafNode++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int root = 0;
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) root = i;
		else graph[parent].push_back(i);
	}

	cin >> nodeToDelete;

	if (nodeToDelete == root) cout << 0;
	else {
		dfs(root);
		cout << numLeafNode;
	}

	return 0;
}