#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 T: 테스트 케이스의 개수
 N: 동전 종류의 수
 M: 동전으로 만들어야 할 금액

- 변수 제한 사항
 T: 1~10
 N: 1~20
 M: 1~10,000

방법의 수 2^31 - 1 보다 작다 => int형으로 나타낼 수 있다.
같은 가치의 동전이 여러번 주어지는 경우는 없다.

- 문제 상황
 동전의 가지 수와 각 동전의 금액이 오름차순으로 정렬되어 주어질 때, 동전으로 목표 금액을 만드는 모든 방법의 수를 구하여라

2. 풀이 계획
 순서에 상관 없이 뽑는 것이므로, 조합 문제이며, 조합 문제는 동전 순서대로 고려해 가는 것으로 판단을 진행한다!

*/

int M, N;

string treasure_map[50];

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

inline bool is_in_scope(int i, int j) {
	if (0 <= i && i < M && 0 <= j && j < N) {
		return true;
	}
	else {
		return false;
	}
}

int bfs(int start_i, int start_j) {
	int time;

	queue<vector<int>> bfs_queue;

	int is_visited[50][50] = { 0, };

	bfs_queue.push({ start_i, start_j, 0 });
	is_visited[start_i][start_j] = 1;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		bfs_queue.pop();
		time = cur_depth;


		for (int i = 0;i < 4;i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (is_in_scope(next_i, next_j) && is_visited[next_i][next_j] == 0 && treasure_map[next_i][next_j] == 'L') {
				is_visited[next_i][next_j] = 1;
				bfs_queue.push({ next_i, next_j, cur_depth + 1 });
			}
		}
	}

	return time;
}


int solution() {
	int answer = 0;

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (treasure_map[i][j] == 'L') {
				answer = max(answer, bfs(i, j));
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0;i < M;i++) {
		cin >> treasure_map[i];
	}

	cout << solution() << '\n';
}