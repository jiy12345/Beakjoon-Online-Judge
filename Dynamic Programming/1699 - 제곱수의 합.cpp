#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 제곱수의 합으로 나타낼 변수

- 변수 제한 사항
 N: 1~100,000

- 문제 상황
 주어진 자연수 N을 제곱수들의 합으로 표현할 때, 그 항의 최소 개수를 구하라.

2. 풀이 계획
 BFS로하여 방문한 노드는 다시 방문하지 않도록 하면 될듯하다!

3. 계획 검증

*/

bool is_visited[100001] = { false };

int N;

int solution() {
	queue<vector<int>> bfs_queue;

	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front()[0];
		int cur_depth = bfs_queue.front()[1];

		bfs_queue.pop();
		
		if (cur_num == 0) {
			return cur_depth;
		}

		int next_num;
		int k = 1;

		while (k * k <= cur_num) {
			next_num = cur_num - k * k;
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