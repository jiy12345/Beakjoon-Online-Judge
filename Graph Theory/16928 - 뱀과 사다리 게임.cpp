#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 사다리의 수
M: 뱀의 수

- 변수 제한 사항


- 문제 상황
점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.

 - 모든 k개의 점은 서로 다르다.
 - k는 4보다 크거나 같다.
 - 모든 점의 색은 같다.
 - 모든 1 ≤ i ≤ k-1에 대해서, di와 di+1은 인접하다. 또, dk와 d1도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.

게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 여부를 판단하라.

 2. 풀이 계획
 벽을 최소 몇개 부수어야 하는지에 대한 문제이므로, 벽이 부서질 때만 비용이 발생한다고 보면 된다.

 따라서 0 - 1 BFS라고 볼 수 있다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N, M;
bool isVisited[101];
int ladderAndSnake[101];


int solution() {
	int answer = 0;

	queue<pair<int, int>> bfs_queue;

	bfs_queue.push(make_pair(1, 0));
	isVisited[0] = true;

	while (!bfs_queue.empty()) {
		int cur_loc = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		cout << "cur_loc: " << cur_loc << endl;
		cout << "cur_depth: " << cur_depth << endl;

		if (cur_loc == 100) {
			answer = cur_depth;
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int next_loc = cur_loc + i;

			if (next_loc <= 100) {
				cout << "next_loc: " << next_loc << endl;
				if (ladderAndSnake[next_loc] != 0) next_loc = ladderAndSnake[next_loc];
				cout << "next_loc: " << next_loc << endl << endl;

				if (isVisited[next_loc] == false) {
					isVisited[next_loc] = true;
					bfs_queue.push(make_pair(next_loc, cur_depth + 1));
				}
			}

		}
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int start, end;
		cin >> start >> end;
		ladderAndSnake[start] = end;
	}

	cout << solution();

	return 0;
}