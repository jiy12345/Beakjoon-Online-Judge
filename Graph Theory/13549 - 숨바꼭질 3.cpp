#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수빈이의 현재 위치
K: 동생의 현재 이ㅜ치

- 변수 제한 사항
N: 0 ~ 100,000
K: 0 ~ 100,000

- 문제 상황
 수빈이와 동생의 위치가 주어지고, 수빈이는 다음과 같이 이동한다고 하자.

 수빈이의 현 위치가 X일 때,

 - 걷기: 1초후에 X - 1 or X + 1
 - 순간이동: 0초 후에 2 * X

 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

2. 풀이 계획

0 - 1 로 간선이 서로 다른 가중치를 가지고 있기는 하지만, 

우선순위 큐를 이동한다면?
 => 어떤 노드를 먼저 방문 했다고 했을 때, 그 방문까지 걸린 시간이 최단시간이라고 보장할 수 없기 때문에 안된다. 

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

inline bool isInRange(int X) {
	return (0 <= X && X <= 200000);
}

int solution(int N, int K) {
	int distance[200001];
	int timeSpent = 0;

	fill_n(distance, 200001, 1e9);
	distance[N] = 0;

	deque<int>bfs_queue;

	bfs_queue.push_back(N);

	while (!bfs_queue.empty()) {
		int cur_location = bfs_queue.front();
		bfs_queue.pop_front();

		if (cur_location == K) {
			break;
		}

		int next_location = cur_location + 1;
		if (isInRange(next_location) && distance[cur_location] + 1 < distance[next_location]) {
			distance[next_location] = distance[cur_location] + 1;
			bfs_queue.push_back(next_location);
		}

		next_location = cur_location - 1;
		if (isInRange(next_location) && distance[cur_location] + 1 < distance[next_location]) {
			distance[next_location] = distance[cur_location] + 1;
			bfs_queue.push_back(next_location);
		}

		next_location = 2 * cur_location;
		if (isInRange(next_location) && distance[cur_location] < distance[next_location]) {
			distance[next_location] = distance[cur_location];
			bfs_queue.push_front(next_location);
		}
	}

	return distance[K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	cout << solution(N, K);

	return 0;
}