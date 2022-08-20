#include<iostream>
using namespace std;

int N, M;

int solution() {
	int answer = 0;
	int curBox = M;

	for (int i = 0; i < N; i++) {
		int bookWeight;
		cin >> bookWeight;

		if (curBox + bookWeight > M) {
			answer++;
			curBox = bookWeight;
		}
		else
			curBox += bookWeight;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	cout << solution();

	return 0;
}
