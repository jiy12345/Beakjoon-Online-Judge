#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 이미 방문한 노드를 표시해주기 위한 배열
bool is_visited[1000001] = { false };

int N;

int solution() {
	queue<vector<int>> bfs_queue;

	// 시작 위치와 시작 깊이인 0 큐에 푸시
	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		vector<int> temp = bfs_queue.front();
		bfs_queue.pop();
		int cur_N = temp[0];
		int cur_depth = temp[1];

		// BFS로 탐색하였으므로, 처음 1이 발견된 순간 바로 그 순간의 깊이가 최소 연산의 횟수가 됨!
		if (cur_N == 1) {
			return cur_depth;
		}

		int next_N;
		// 3으로 나누어 떨어질 경우
		if (cur_N % 3 == 0) {
			// 3으로 나누는 연산
			next_N = cur_N / 3;
			// 이미 계산된 값이 아닐 경우에만 계산
			if (is_visited[next_N] == false) {
				is_visited[next_N] = true;
				bfs_queue.push({ next_N, cur_depth + 1 });
			}
		}		
		// 2로 나누어 떨어질 경우
		if (cur_N % 2 == 0) {
			// 2로 나누는 연산
			next_N = cur_N / 2;
			// 이미 계산된 값이 아닐 경우에만 계산
			if (is_visited[next_N] == false) {
				is_visited[next_N] = true;
				bfs_queue.push({ next_N, cur_depth + 1 });
			}
		}
		next_N = cur_N - 1;
		// 이미 계산된 값이 아닐 경우에만 계산
		if (is_visited[next_N] == false) {
			is_visited[next_N] = true;
			bfs_queue.push({ next_N, cur_depth + 1 });
		}
	}
	return 0;
}

int main() {
	cin >> N;

	cout << solution();
}
