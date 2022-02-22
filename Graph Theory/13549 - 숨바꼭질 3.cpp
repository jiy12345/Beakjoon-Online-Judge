#include<iostream>
#include<vector>
#include<deque>
using namespace std;

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
