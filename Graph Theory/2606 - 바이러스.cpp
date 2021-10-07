#include<iostream>
#include<queue>
using namespace std;

int N; // 컴퓨터 수
int num_of_link; // 총 입력될 연결의 수
// 1부터 시작하므로 1~100까지 인덱스 사용
bool link_info[101][101] = { {false, }, }; // 컴퓨터간의 연결 정보를 저장할 2차원 배열
bool is_visited[101] = { false }; // 탐색 시 이미 방문한 노드를 표시하기 위한 배열

int solution(int start_computer) {
	int answer = 0;

	queue<int> bfs_queue; // BFS 진행을 위한 큐

	// 첫 노드에서 탐색을 시작하므로 항상 방문 표시 해주기
	is_visited[start_computer] = true;

	bfs_queue.push(start_computer); // 시작 컴퓨터 큐에 푸시

	while (!bfs_queue.empty()) {
		int cur_computer = bfs_queue.front();
		bfs_queue.pop();
		answer++; // 실제 방문 하는 것은 큐에서 팝될 때이므로 큐에서 컴퓨터 하나 팝 할 때마다 바이러스에 걸린 컴퓨터 수 1 증가

		for (int i = 1; i <= N; i++) {
			// 현재 컴퓨터와 연결되며, 방문하지 않은 컴퓨터일 때만 큐에 푸시
			if (link_info[cur_computer][i] == true && is_visited[i] == false) {
				is_visited[i] = true; // 중복 방문 방지를 위해 큐에 푸시될 시 방문 표시 
				bfs_queue.push(i); // 현재 탐색중인 컴퓨터와 연결된 컴퓨터 큐에 푸시
			}
		}
	}
	return answer;
}

int main() {

	cin >> N;
	cin >> num_of_link;

	int start, end;
	for (int i = 0; i < num_of_link; i++) {
		cin >> start >> end;
		// 양방향 연결!
		link_info[start][end] = true;
		link_info[end][start] = true;
	}

	// 1번 컴퓨터는 빼주기 위해 1 빼주기!
	cout << (solution(1) - 1);
}
