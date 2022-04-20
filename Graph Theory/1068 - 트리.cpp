#include<iostream>
#include<vector>
using namespace std;


/*
1. ���� �м�
- ����
N: Ʈ�� ����� ����

 - ���� ���� ����
N: 1 ~ 50

- ���� ��Ȳ
 Ʈ���� ���¿� ���� ��尡 �־����� �� ���� ����� ������ ���Ͽ���

2. Ǯ�� ��ȹ


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define MAX 50

int N, nodeToDelete;
vector<int> graph[MAX];
int numLeafNode;

void dfs(int nodeNum) {
	int numChildNode = 0;

	for (int nextNode : graph[nodeNum]) {
		// ������ ����� ��� �� �������� Ž������ ����
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