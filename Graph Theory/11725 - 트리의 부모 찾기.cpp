#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> graph[100001];
bool isVisited[100001];
int parentNode[100001];

void dfs(int cur_node) {
	for (int i = 0; i < graph[cur_node].size(); i++) {
		int next_node = graph[cur_node][i];
		if (isVisited[next_node] == false) {
			isVisited[next_node] = true;
			parentNode[next_node] = cur_node;
			dfs(next_node);
		}
	}
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

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parentNode[i] << '\n';
	}

	return 0;
}