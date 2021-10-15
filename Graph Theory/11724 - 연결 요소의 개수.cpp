#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
using namespace std;

// 간선의 상태 입력받기 위한 2차원 배열
bool link_status[1001][1001] = { {false,} };
// BFS 진행 시 이미 방문한 노드 표시를 위한 배열
bool is_visited[1001] = { false };

int N, M;

// 각 노드에 대한 BFS를 위한 함수
void bfs(int i) {
	queue<int> bfs_queue;

	// 첫 노드 푸시 및 방문 표시
	bfs_queue.push(i);
	is_visited[i] = true;

	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		for (int j = 1; j <= N; j++) {
			// 연결되어있으며 아직 방문하지 않은 노드만 큐에 푸시
			if (link_status[cur_node][j] == true && is_visited[j] == false) {
				bfs_queue.push(j);
				is_visited[j] = true; // 중복방문 방지를 위해 미리 방문 표시하기
			}
		}
	}
}

int solution() {
	int answer = 0;

	// 노드 번호가 1부터 시작하고 N으로 끝나므로
	for (int i = 1; i <= N; i++) {
		// 방문하지 않은 곳일 경우에만 bfs 진행
		if (is_visited[i] == false) {
			answer++; // bfs를 진행한 횟수 세주기
			bfs(i);
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	string u_and_v;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		link_status[u][v] = true;
		link_status[v][u] = true;
	}

	cout << solution();
}
