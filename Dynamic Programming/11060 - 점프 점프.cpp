#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 1000

int N;
int maze[MAX];
int minNumOfJump[MAX];

bool isInRange(int i) {
	return 0 <= i && i < N;
}

int bfs() {
	int answer = -1;
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ 0,0 });
	minNumOfJump[0] = 0;

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front()[0];
		int cur_i = bfs_queue.front()[1];
		bfs_queue.pop();

		if (cur_i == N - 1) {
			answer = cur_depth;
			break;
		}

		for (int i = 1; i <= maze[cur_i]; i++) {
			int right = cur_i + i;
			int left = cur_i - i;

			if (isInRange(right) == true && minNumOfJump[right] > cur_depth + 1) {
				minNumOfJump[right] = cur_depth + 1;
				bfs_queue.push({ cur_depth + 1, right });
			}

			if (isInRange(left) == true && minNumOfJump[left] > cur_depth + 1) {
				minNumOfJump[left] = cur_depth + 1;
				bfs_queue.push({ cur_depth + 1, left });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> maze[i];

	fill(&minNumOfJump[0], &minNumOfJump[N], MAX);

	cout << bfs();
}
