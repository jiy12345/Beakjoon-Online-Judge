#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석

- 변수
N: 총 컴퓨터의 수



- 변수 제한 사항
N:1~100

- 문제 상황
 컴퓨터간의 연결 정보가 주어지고, 1번 컴퓨터부터 웜바이러스에 걸리며, 연결된 모든 컴퓨터가 웜 바이러스에 걸린다고 할 때,
 총 웜 바이러스에 걸리게 되는 컴퓨터의 수를 구하라

2. 풀이 계획
연결상황이 명확하지 않아 정확히 체크할 수는 없지만, 이렇게 복잡한 연결이 있을 수 있는 문제, 그리고 한번씩의 방문만 있으면 되는 문제는 
BFS로 진행하되 방문 표시를 큐에 푸시하여 중복 방문 하지 않도록 하는 것이 가장 효과적이다!

또한 컴퓨터의 수가 100개로 그리 많지 않으므로 100 x 100 이차원 배열을 통해 두 컴퓨터간의 연결을 표현하면 될 듯 하다!

따라서 자세한 계획은 다음과 같다.

1. 2차원 bool형 배열에 연결정보를 입력받아 연결된 곳은 true, 나머지는 false로 표시한다.
2. 1을 큐에 푸시하고, BFS 탐색을 진행한다.



3. 계획 검증


*/
int N; // 컴퓨터 수
int num_of_link;
bool link_info[101][101] = { {false, }, };
bool is_visited[101] = { false };

int solution(int start_computer) {
	int answer = 0;

	queue<int> bfs_queue;

	is_visited[start_computer] = true;

	bfs_queue.push(start_computer);

	while (!bfs_queue.empty()) {
		int cur_computer = bfs_queue.front();
		bfs_queue.pop();
		answer++;

		for (int i = 1; i <= N; i++) {
			if (link_info[cur_computer][i] == true && is_visited[i] == false) {
				is_visited[i] = true; // 중복 방문 방지를 위해 큐에 푸시될 시 방문 표시 
				bfs_queue.push(i);
			}
		}
	}
	return answer;
}

int main() {

	cin >> N;
	cin >> num_of_link;

	// 양방향 연결!
	int start, end;
	for (int i = 0; i < num_of_link; i++) {
		cin >> start >> end;
		link_info[start][end] = true;
		link_info[end][start] = true;
	}

	// 1번 컴퓨터는 빼주기 위해 1 빼주기!
	cout << (solution(1) - 1);
}