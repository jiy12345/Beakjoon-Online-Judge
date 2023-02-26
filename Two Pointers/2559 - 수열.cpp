#include<iostream>
using namespace std;

int N, K;
int temperatures[100000];

int solution() {
	int cur_sum = 0;

	for (int i = 0;i < K;i++) {
		cur_sum += temperatures[i];
	}

	int max_num = cur_sum;

	for (int i = K;i < N;i++) {
		cur_sum = cur_sum - temperatures[i - K] + temperatures[i];
		max_num = max(max_num, cur_sum);
	}

	return max_num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		cin >> temperatures[i];
	}

	cout << solution();
}