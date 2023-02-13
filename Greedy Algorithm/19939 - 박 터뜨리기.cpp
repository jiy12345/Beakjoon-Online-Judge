#include<iostream>
using namespace std;

int N, K;

int solution() {
	int sum = K * (K + 1) / 2;
	if (N - sum < 0) {
		return -1;
	}
	if ((N - sum) % K == 0) {
		return K - 1;
	}
	else {
		return K;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	cout << solution();
}