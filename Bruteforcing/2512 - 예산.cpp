#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

int N, M;
int budgets[10000];

int solution() {
	int sum = accumulate(budgets, budgets + N, 0);
	if(sum <= M){
		return *max_element(budgets, budgets+N);
	}

	int cur_maximum = M / N;
	while (true) {
		sum = 0;
		for (int i = 0;i < N;i++) {
			sum += (budgets[i] > cur_maximum) ? cur_maximum : budgets[i];
		}

		if (sum > M) {
			return cur_maximum - 1;
		}

		cur_maximum++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> budgets[i];
	}

	cin >> M;

	cout << solution();
}