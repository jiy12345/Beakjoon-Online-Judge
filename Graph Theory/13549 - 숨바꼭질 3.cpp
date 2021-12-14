#include<iostream>
#include<queue>
using namespace std;

int N, K;

bool is_visited[100001];

void solution() {
	int optimal_time = 100001;
	int num_optimal_route = 0;

	queue<pair<int, int>> bfs_queue;

	// 첫 위치 설정
	bfs_queue.push({ N, 0 });

	is_visited[N] = true;

	while (!bfs_queue.empty()) {
		int X = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();

		// pop할 시 방문 표시
		is_visited[X] = true;

		// 최적 시간 이상의 시간 탐색이 시작되었을 때 빠져나가기
		if (cur_depth > optimal_time) {
			break;
		}

		if (X == K) {
			optimal_time = cur_depth;
			num_optimal_route++;
		}


		// X - 1
		if ((X - 1 >= 0) && (is_visited[X - 1] == false)) {
			bfs_queue.push({ X - 1, cur_depth + 1 });
		}		

		// X + 1
		if ((X + 1 <= 100000) && (is_visited[X + 1] == false)) {
			bfs_queue.push({ X + 1, cur_depth + 1 });
		}

		// 2 * x
		if ((2 * X  <= 100000) && (is_visited[2 * X] == false)) {
			bfs_queue.push({ 2 * X, cur_depth + 1 });
		}
	}

	cout << optimal_time << '\n';
	cout << num_optimal_route << '\n';
}

int main() {
	cin >> N >> K;

	solution();
}
