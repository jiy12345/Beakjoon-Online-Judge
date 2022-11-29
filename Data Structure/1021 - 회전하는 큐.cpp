#include<iostream>
#include<deque>
using namespace std;

int N, M;
deque<int> Deque;

int solution() {
	int answer = 0;
	for (int i = 0; i < M; i++) {
		int targetNum;
		cin >> targetNum;
		
		int curMoveNum = 0;
		while (true) {
			if (Deque.front() == targetNum) {
				Deque.pop_front();
				break;
			}

			int temp = Deque.front();
			Deque.pop_front();
			Deque.push_back(temp);
			curMoveNum++;
		}

		if (curMoveNum > (Deque.size() + 1) / 2)
			curMoveNum = (Deque.size() + 1) - curMoveNum;

		answer += curMoveNum;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	Deque.resize(N);
	for (int i = 0; i < N; i++)
		Deque[i] = i + 1;

	cout << solution();
}