#include<iostream>
#include<algorithm>
using namespace std;

int N;
int customers[100000];

long long solution() {
	sort(customers, customers + N, greater<>());
	long long total_tip = 0;

	int cur_order = 0;
	while (true) {
		total_tip += customers[cur_order] - cur_order;

		cur_order++;
		if (customers[cur_order] - cur_order <= 0) break;
	}

	return total_tip;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> customers[i];
	}

	cout << solution();
}