#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 10001

int N, M;
vector<int> graph[MAX];
int numHack[MAX];
bool isVisited[MAX];

int dfs(int cur_node) {
	isVisited[cur_node] = true;

	int cur_numHack = 1; // 기본적으로 현재 컴퓨터는 항상 해킹 되므로

	for (int next_node : graph[cur_node])
		if (isVisited[next_node] == false) 
			cur_numHack += dfs(next_node);

	return cur_numHack;
}

void solution() {
	int maxNum = 0;

	// 모든 노드에 대해 탐색하며 각 컴퓨터를 해킹했을 때 해킹할 수 있는 컴퓨터의 수 찾고,
	// 그 최대값 구하기
	for (int i = 1; i <= N; i++) {
		memset(isVisited, false, sizeof(isVisited));
		numHack[i] = dfs(i);
		maxNum = max(maxNum, numHack[i]);
	}

	for (int i = 1; i <= N; i++) {
		// cout << numHack[i] << " ";
		if (numHack[i] == maxNum) cout << i << " ";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int root = 0;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}

	solution();

	return 0;
}
