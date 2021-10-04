#include<iostream>
#include<queue>
using namespace std;

int N, M; // 정점 개수, 간선 개수

bool link[1001][1001] = { {false,}, }; // 두 지점간의 간선이 있는지 표시하는 배열 

// 각 알고리즘에서 탐색 시 방문한 노드를 표시하기 위한 배열!
bool node_visited_dfs[1001] = { false, };
bool node_visited_bfs[1001] = { false, };

void DFS(int cur_node) {
	// 첫 노드는 무조건 방문해야 하므로
	node_visited_dfs[cur_node] = true;
	cout << cur_node << " ";
	// 종료조건이 딱히 없이 더이상 탐색할 노드가 없으면 종료됨!
	for (int i = 1; i <= N;i++) {
		// 연결되어 있으며, 아직 방문하지 않은 노드일 경우에만 탐색
		if (link[cur_node][i] == true && node_visited_dfs[i] == false) {
			DFS(i);
		}
	}
}

void BFS(int start_node) {
	queue<int> bfs_queue; // 방문할 노드의 순서를 저장하기 위한 큐
	bfs_queue.push(start_node); // 큐에 현재 노드 집어 넣기
	node_visited_bfs[start_node] = true; // 첫 노드는 무조건 방문해야 하므로
	while (!bfs_queue.empty()) {
		// 큐의 가장 앞쪽에 있는 노드 빼오기
		int cur_node = bfs_queue.front();
		bfs_queue.pop();
		cout << cur_node << " ";
		
		for (int i = 1; i <= N; i++) {
			// 연결되어 있으며, 아직 방문하지 않은 노드일 경우에만 다음 탐색할 목록에 넣음
			if (link[cur_node][i] == true && node_visited_bfs[i] == false) {
				node_visited_bfs[i] = true; 
				bfs_queue.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V; // 탐색 시작지점

	cin >> N >> M >> V;

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		// 간선은 양방향이므로 양쪽방향으로 모두 입력
		link[start][end]=true;
		link[end][start]=true;
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}
