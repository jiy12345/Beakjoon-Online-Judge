#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> priorityQueue;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;

			if (priorityQueue.size() < N) {
				priorityQueue.push(num);
			} // 가장 큰 수 N개만 유지하면 되므로, 현재 큐의 최소값보다 큰 수만 받기
			else if (num > priorityQueue.top()) {
				priorityQueue.push(num);
				priorityQueue.pop();
			}
		}
	}

	cout << priorityQueue.top();
}
