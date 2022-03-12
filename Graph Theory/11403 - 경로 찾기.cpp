#include<iostream>
#include<queue>
using namespace std;

int N;

int graph[100][100];

int answer[100][100];


void bfs(int cur_graph[100][100], int start_node) {
	queue<int> bfs_queue;
	// 각 위치에서 연결된 노드 모두 푸시
	for (int i = 0;i < N;i++) {
		// 이미 탐색한 노드 표시
		if (cur_graph[start_node][i] == 1) {
			// 경로가 있다는 표시
			answer[start_node][i] = 1;
			// 이미 탐색한 경로임을 표시
			cur_graph[start_node][i] = 0;
			// 노드 큐에 푸시
			bfs_queue.push(i);
		}
	}

	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		// 각 위치에서 연결된 노드 모두 푸시
		for (int i = 0;i < N;i++) {
			// 이미 탐색한 노드 표시
			if (cur_graph[cur_node][i] == 1) {
				// 경로가 있다는 표시
				answer[start_node][i] = 1;
				// 이미 탐색한 경로임을 표시
				cur_graph[cur_node][i] = 0;
				// 노드 큐에 푸시
				bfs_queue.push(i);
			}
		}
	}
}

void solution() {
	// 각각의 모든 노드에 대해서 체크
	for (int i = 0;i < N;i++) {
		int cur_graph[100][100];
		copy(&graph[0][0], &graph[0][0] + 100 * 100, &cur_graph[0][0]);
		bfs(cur_graph, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> graph[i][j];
		}
	}

	solution();

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
