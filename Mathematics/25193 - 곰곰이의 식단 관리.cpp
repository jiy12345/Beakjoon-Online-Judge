#include<iostream>
using namespace std;

int N;

int solution() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		char input;
		cin >> input;
		if (input == 'C') cnt++;
	}

	return cnt / (N - cnt + 1) + (cnt % (N - cnt + 1) != 0 ? 1 : 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	cout << solution();
}