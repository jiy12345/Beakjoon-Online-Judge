#include<iostream>
using namespace std;

int T, N, M;

int solution() {
	for (int i = 0;i < M;i++) {
		int departure, arrival;
		cin >> departure >> arrival;
	}
	return N - 1;
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