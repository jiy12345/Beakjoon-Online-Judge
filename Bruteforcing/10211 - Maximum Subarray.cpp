#include<iostream>
using namespace std;

int T, N;
int X[1000];

int solution() {
	int max_sum = -1000 * 1000;

	for (int i = 0;i < N;i++) {
		int cur_sum = 0;
		for (int j = i;j < N;j++) {
			cur_sum += X[j];
			max_sum = max(max_sum, cur_sum);
		}
	}

	return max_sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0;i < T;i++) {
		cin >> N;
		for (int i = 0;i < N;i++) {
			cin >> X[i];
		}

		cout << solution() << '\n';
	}
}