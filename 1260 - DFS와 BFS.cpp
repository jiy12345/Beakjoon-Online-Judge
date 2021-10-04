#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석

- 변수
N: 정점의 개수
M: 간선의 개수
V: 탐색을 시작할 지점

- 변수 제한 사항
N: 1~1,000
M: 1~10,000
두 정점 사이에 여러개의 간선이 있을 수 있음!

- 문제 상황
입력으로 들어온 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력한다!

2. 풀이 계획
일단 두 정점 사이에 여러개의 간선이 있을 수 있으므로, int형 1000 x 1000 베열을 만들어 간선의 개수를 정한다!

각각의 함수를 정의하여 dfs

3. 계획 검증


*/
int N, M;

int num_of_link_dfs[1001][1001] = { {0,}, }; // 두 지점간의 간선의 개수 표시하는 
int num_of_link_bfs[1001][1001] = { {0,}, }; // 두 지점간의 간선의 개수 표시하는 

bool node_visited_dfs[1001] = { false, };
bool node_visited_bfs[1001] = { false, };


void DFS(int cur_node) {
	node_visited_dfs[cur_node] = true;
	cout << cur_node <<" ";
	// 종료조건이 딱히 없이 더이상 연결할 노드가 없으면 종료됨!
	for (int i = 1; i <= N;i++) {
		if (num_of_link_dfs[cur_node][i] != 0 && node_visited_dfs[i] == false) {
			num_of_link_dfs[cur_node][i]--;
			num_of_link_dfs[i][cur_node]--;

			DFS(i);
		}
	}
}

void BFS(int start_node) {
	queue<int> bfs_queue;
	bfs_queue.push(start_node);
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();
		node_visited_bfs[cur_node] = true;
		cout << cur_node << " ";

		for (int i = 1; i <= N; i++) {
			if (num_of_link_bfs[cur_node][i] != 0 && node_visited_bfs[i] == false) {
				num_of_link_bfs[cur_node][i]--;
				num_of_link_bfs[i][cur_node]--;
				bfs_queue.push(i);
			}
		}
	}
}

int main() {
	int V;

	cin >> N >> M >> V;

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		num_of_link_dfs[start][end]++;
		num_of_link_dfs[end][start]++;
		num_of_link_bfs[start][end]++;
		num_of_link_bfs[end][start]++;
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}