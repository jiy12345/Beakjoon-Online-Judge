#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
