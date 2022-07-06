#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 미로의 길이
Ai: i번째 칸에서 점프할 수 있는 최대 거리

- 변수 제한 사항
N: 1 ~ 1,000
A: 0 ~ 100

- 문제 상황
 미로의 가장 왼쪽 끝에서 오른쪽 끝으로 가야 한다고 할 때, 최소 몇번 점프를 해야 갈 수 있는지를 구하여라.

2. 풀이 계획
 앞서 온 곳에 따라 뒤의 경로가 달라지지 않으므로, 각 위치에 최소 점프 횟수로 도달할 때만 방문하면 될 듯 하다.

따라서 각 위치에 대해 이동횟수의 최대값으로 초기화하고, bfs를 진행하되, 방문했을 때의 점프 횟수가 이미 저장된 점프횟수보다 작을 때만 방문하도록 한다!

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

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