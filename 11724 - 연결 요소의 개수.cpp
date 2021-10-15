#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 정점의 개수
M: 간선의 개수

- 변수 제한 사항
1 ≤ N ≤ 1,000,
0 ≤ M ≤ N×(N-1)/2

양 끝점을 u, v라 할 때,
1 ≤ u, v ≤ N

- 문제 상황
정점의 개수와 간선의 개수가 주어지고, 간선의 연결 상태가 주어질 때,
연결 요소의 개수를 출력한다.

2. 풀이 계획
 연결 요소란, 무향 그래프에서 정점 간 경로가 연결되어 있으며, 그래프의 나머지 정점과는 연결되어있지 않은 부분 그래프를 말한다.

따라서 연결 요소를 탐색하기 위해서는 모든 정점을 방문하여 연결을 체크해야 한다.
방향이 없는 그래프이므로 한쪽에서 정점을 통해 방문한 정점은 다시 체크할 필요가 없다!
따라서 아직 방문하지 않은 모든 노드에 대해 BFS를 진행하고, BFS를 진행한 횟수를 세면 연결 요소의 개수가 될 듯 하다!

자세한 계획은 다음과 같다.

1. 이차원 배열에 연결 상태를 입력받으며, 방문 표시를 할 bool형 배열을 정점의 개수 만큼의 크기로 생성한다.
2. 모든 위치에 대해 중복을 방지한(큐에 푸시할 때 방문 표시) BFS를 진행하고, 그 횟수를 출력한다. 

3. 계획 검증
 양방향 연결이므로 어떤 노드에서 시작하든지 중복 방지한 BFS를 진행하면 같은 연결 요소 내에 위치한 노드들은 모두 탐색할 수 있다.

 또한 아직 방문하지 않은 노드에 대해 모두 탐색하므로, 모든 연결 요소를 체크할 수 있으며, BFS를 진행하며 모두 방문 표시를 진행하므로, 하나의 연결 요소가 중복하여 세지거나 할 일이 없다.


 시간 복잡도 측면에서는 중복을 제거한 BFS를 진행하므로 각 노드를 단 한번씩만 방문하고, 따라서 시간복잡도는 O(N)으로 나타낼 수 있다. 따라서 1,000이라는 입력에 대해서는 문제없이 동작할 것으로 보인다.

 입력의 크기가 최대일 경우 연결 상태를 나타내기 위한 이차원 배열의 크기는 다음과 같으며, 
 1,000 x 1,000 x 1(bool형 크기) = 4,000,000(바이트) = 4(메가바이트)
 나머지 배열과 BFS를 위한 큐는 각각 최대 1,000바이트, 4,000바이트(정수형 배열)가 될 수 있는데, 이를 다 합하여도 메모리 제한인 512MB에 한참 못미치므로 크게 문제가 없을 듯 하다

*/

bool link_status[1001][1001] = { {false,} };
bool is_visited[1001] = { false };

int N, M;

void bfs(int i) {
	queue<int> bfs_queue;

	bfs_queue.push(i);
	is_visited[i] = true;

	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		for (int j = 1; j <= N; j++) {
			// 연결되어있으며 아직 방문하지 않은 노드만 큐에 푸시
			if (link_status[cur_node][j] == true && is_visited[j] == false) {
				bfs_queue.push(j);
				is_visited[j] = true; // 중복방문 방지를 위해 방문 표시하기
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

	cin.ignore(); // 앞서 입력된 엔터키(개행문자 '\n' 를 버퍼에서 제거하기 위해)

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		link_status[u][v] = true;
		link_status[v][u] = true;
	}

	cout << solution();
}