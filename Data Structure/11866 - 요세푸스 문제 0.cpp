#include<iostream>
#include<queue>
using namespace std;

int N, K;
queue<int> q;

void solution() {
	for (int i = 1; i <= N; i++) 
		q.push(i);

	cout << "<";
	while (true) {

		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		
		if (q.size() == 1) break;
		cout << ", ";
		q.pop();
	}
	cout << ">";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	solution();
}