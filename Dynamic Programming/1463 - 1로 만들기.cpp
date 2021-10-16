#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 연산을 진행할 변수

- 변수 제한 사항
 N: 1~1,000,000

- 문제 상황
정수 X에 사용할 수 있는 연산이 다음과 같이 3가지라고 했을 때,

1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.

위의 연산들을 사용하여 X를 1로 만들 수 있는 연산 횟수의 최솟값을 구하여라.

2. 풀이 계획
 BFS로하여 방문한 노드는 다시 방문하지 않도록 하면 될듯하다!

3. 계획 검증

*/

bool is_visited[1000001] = { false };

int N;

int solution() {
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		vector<int> temp = bfs_queue.front();
		bfs_queue.pop();
		int cur_N = temp[0];
		int cur_depth = temp[1];

		if (cur_N == 1) {
			return cur_depth;
		}

		int next_N;
		// 3으로 나누어 떨어질 경우
		if (cur_N % 3 == 0) {
			next_N = cur_N / 3;
			// 이미 계산된 값이 아닐 경우에만 계산
			if (is_visited[next_N] == false) {
				is_visited[next_N] = true;
				bfs_queue.push({ next_N, cur_depth + 1 });
			}
		}		
		// 2로 나누어 떨어질 경우
		if (cur_N % 2 == 0) {
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