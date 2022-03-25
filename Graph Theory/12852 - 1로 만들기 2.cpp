#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 처음에 주어진 수

- 변수 제한 사항
1 ≤ N <= 1,000,000

건물은 1층부터 시작

- 문제 상황
 어떤 수 N이 주어졌을 때 다음과 같은 세가지 연산으로

1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.

1을 만드 수 있는 연산의 최소 횟수와
N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분하여 순서대로 출력한다!

2. 풀이 계획
걍 bfs진행하고, 이전 수를 기록 하면 될 듯 하다.

배열을 사용하느냐, 아니면 큐에 같이 정보를 푸시하느냐인데, 어떤게 메모리를 적게 쓸지는 한번 해봐야 알듯

3. 계획 검증

bfs는 그런데 거리상 가까운 노드가 먼저 나온다.

거리가 가까운 것이 회전수가 적다는 것을 보장하는가?
그렇지 않다. 따라서 priority_queue를 사용하여 회전 수에 따라서 정렬되도록 해야할 듯 하다.


*/

#define MAX 1000001

int N;
bool isVisited[MAX];

void solution() {

	queue<pair<int, pair<int,vector<int>>>> bfs_queue;
	bfs_queue.push({ N, {0, { N } } });
	isVisited[N] = true;

	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second.first;
		vector<int> cur_route(bfs_queue.front().second.second);
		bfs_queue.pop();

		cout << "cur_num: " << cur_num << endl;

		if (cur_num == 1) {
			cout << cur_depth << '\n';
			for (int i = 0; i < cur_route.size(); i++) {
				cout << cur_route[i] << " ";
			}
			break;
		}
		
		int next_num;
		if (cur_num % 3 == 0) {
			next_num = cur_num / 3;

			if (next_num >= 1 && isVisited[next_num] == false) {
				isVisited[next_num] = true;
				cur_route.push_back(next_num);
				bfs_queue.push({ next_num, {cur_depth + 1, cur_route} });
				cur_route.pop_back();
			}
		}

		if (cur_num % 2 == 0) {
			next_num = cur_num / 2;

			if (next_num >= 1 && isVisited[next_num] == false) {
				isVisited[next_num] = true;
				cur_route.push_back(next_num);
				bfs_queue.push({ next_num, {cur_depth + 1, cur_route} });
				cur_route.pop_back();
			}
		}

		next_num = cur_num - 1;
		if (next_num >= 1 && isVisited[next_num] == false) {
			isVisited[next_num] = true;
			cur_route.push_back(next_num);
			bfs_queue.push({ next_num, {cur_depth + 1, cur_route} });
			cur_route.pop_back();
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();

	return 0;
}
