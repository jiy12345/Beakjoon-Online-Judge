#include<iostream>
#include<queue>
using namespace std;

int A, B;

int bfs() {
	int answer = -1;

	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ 0, B });

	while (!bfs_queue.empty()) {
		int cur_depth	= bfs_queue.front().first;
		int cur_i	= bfs_queue.front().second;
		bfs_queue.pop();

		if (cur_i <= A) {
			if(cur_i == A) answer = cur_depth + 1;
			break;
		}

		int next_depth = cur_depth + 1;

		// 연산 1의 반대. 2로 나누기
		if (cur_i % 2 == 0) {
			int next_i = cur_i >> 1;
			bfs_queue.push({ next_depth, next_i });
		}

		// 연산 2의 반대. 1을 빼고 10으로 나누기
		if ((cur_i - 1) % 10 == 0) {
			int next_i = (cur_i -1) / 10;
			bfs_queue.push({ next_depth, next_i });
		}
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	cout << bfs();
}
