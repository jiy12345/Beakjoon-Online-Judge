#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수빈이의 현재 위치
K: 동생의 현재 위치

- 변수 제한 사항
N: 0 ~ 100,000
K: 0 ~ 100,000

- 문제 상황
 현위치가 X라고 할 때, 수빈이가 다음과 같이 움직인다고 하면, 
 
 - X-1, X+1
 - 2*X

 수빈이가 동생을 찾는 가장 빠른 시간과 어떻게 이동해야 하는지를 출력한다.

2. 풀이 계획

전형적인 BFS 문제이다

아직 방문하지 않은(큐에 푸시되지 않은) 노드이며 
3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


inline bool isInRange(int X) {
	return (0 <= X && X <= 200000);
}

void solution(int N, int K) {
	vector<int>routeBackward(200001);
	vector<bool>isVisited(200001);
	queue<pair<int, int>>bfs_queue;

	int timeSpent = 0;

	bfs_queue.push({ N, 0 });

	while (!bfs_queue.empty()) {
		int cur_location = bfs_queue.front().first;

		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();

		if (cur_location == K) {
			timeSpent = cur_depth;
			break;
		}

		int next_location = cur_location + 1;
		if (isInRange(next_location) && isVisited[next_location] == false) {
			isVisited[next_location] = true;
			routeBackward[next_location] = cur_location;
			bfs_queue.push({ next_location, cur_depth + 1 });
		}

		next_location = cur_location - 1;
		if (isInRange(next_location) && isVisited[next_location] == false) {
			isVisited[next_location] = true;
			routeBackward[next_location] = cur_location;
			bfs_queue.push({ next_location, cur_depth + 1 });
		}

		next_location = 2 * cur_location;
		if (isInRange(next_location) && isVisited[next_location] == false) {
			isVisited[next_location] = true;
			routeBackward[next_location] = cur_location;
			bfs_queue.push({ next_location, cur_depth + 1 });
		}
	}

	cout << timeSpent << '\n';

	int cur_location = K;
	vector <int> route;
	while (true) {
		route.push_back(cur_location);

		if (cur_location == N) break;

		cur_location = routeBackward[cur_location];
	}

	for (int i = route.size() - 1; i >= 0; i--) {
		cout << route[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	solution(N, K);

	return 0;
}