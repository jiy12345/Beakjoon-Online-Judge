#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 이미 계산한 수는 계산하지 않도록 하기
bool is_visited[100001] = { false };

int N;

int solution() {
	queue<vector<int>> bfs_queue;

	// N부터 시작하여 제곱수를 빼가며 계산
	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front()[0];
		int cur_depth = bfs_queue.front()[1];

		bfs_queue.pop();
		
		// 현재 0일 경우 제곱수의 합으로 나타낸 것
		// BFS로 탐색하였으므로 가장 먼저 연산한 것이 최소 개수 연산!
		if (cur_num == 0) {
			return cur_depth;
		}

		int next_num;
		int k = 1;

		// cur_num보다 커지지 않는 제곱수에 대해 모두 연산
		while (k * k <= cur_num) {
			next_num = cur_num - k * k;
			// 연산하지 않은 값에 대해서만 연산
			if (is_visited[next_num] == false) {
				is_visited[next_num] = true;
				bfs_queue.push({ next_num, cur_depth + 1 });
			}
			k++;
		}	
	}
}

int main() {
	cin >> N;

	cout << solution();
}
