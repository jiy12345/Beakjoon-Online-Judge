#include<iostream>
#include<vector>
using namespace std;

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
