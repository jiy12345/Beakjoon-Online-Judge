#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> graph[100001];
bool isVisited[100001];
int parentNode[100001];

int dfs(int cur_node, int cur_dist, int end_node) {
	if (cur_node == end_node) return cur_dist;

	for (int i = 0; i < graph[cur_node].size(); i++) {
		int next_node = graph[cur_node][i];
		if (isVisited[next_node] == false) {
			isVisited[next_node] = true;
			int result = dfs(next_node, cur_dist + 1, end_node);
			if (result != -1) return result;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int start_node, end_node;

	cin >> n;

	cin >> start_node >> end_node;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		graph[parent].push_back(child);
		graph[child].push_back(parent);
	}

	cout << dfs(start_node, 0, end_node);

	return 0;
}
