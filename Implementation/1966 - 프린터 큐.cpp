#include<iostream>
#include<queue>
using namespace std;

int N, M, T;


int solution() {
	queue<pair<int, int>> printer_queue;
	priority_queue<int> priorities;

	for (int i = 0;i < N;i++) {
		int priority;
		cin >> priority;

		printer_queue.push({ priority, i });
		priorities.push(priority);
	}

	int cnt = 1;
	while (true) {
		int cur_priority = priorities.top();
		priorities.pop();
		while (cur_priority != printer_queue.front().first) {
			auto cur_value = printer_queue.front();
			printer_queue.pop();
			printer_queue.push(cur_value);
		}

		if (printer_queue.front().second == M) {
			break;
		}

		printer_queue.pop();
		cnt++;
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0;i < T;i++) {
		cin >> N >> M;

		cout << solution() << '\n';
	}
}