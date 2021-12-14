#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 수빈이의 현재 위치
 K 동생의 현재 위치

- 변수 제한 사항
 N: 1~100,000
 K: 1~100,000


- 문제 상황
수빈이의 이동 방법은 다음과 같다.

 수빈이의 현재 위치를 X라고 할 때, 

 1. 걷기: 1초후 X-1혹은 X+1 위치로 이동

 2. 순간이동: 1초후 2*X위치로 이동

 동생과 수빈이의 위치가 주어질 때, 가장 빠른 시간이 몇 초 후인지와 가장 빠른 시간으로 찾는 방법이 몇가지인지를 찾아라!


2. 풀이 계획

일단 가중치가 같은 경로찾기 문제이므로 당연히 BFS로 처리하면 될듯 하고,

마지막에 최적 경로를 찾으면 바로 빠져나가는 것이 아닌 그 깊이에 있는 것들 중 원하는 위치에 도착한 경로들의 개수를 세고,

깊이가 다음 깊이로 넘아갔을 경우 멈추면 될 듯 하다!

*/

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