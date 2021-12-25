#include<iostream>
#include<algorithm>
using namespace std;

int N;
int weight[1000];

int solution() {
	sort(weight, weight + N);

	int cur_sum = 0;

	for (int i = 0; i < N; i++) {
		if (cur_sum + 2 <= weight[i]) {
			break;
		}

		cur_sum += weight[i];
	}
	
	return cur_sum + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	cout << solution()';

	return 0;
}
