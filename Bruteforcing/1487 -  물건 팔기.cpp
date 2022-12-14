#include<iostream>
#include<algorithm>
using namespace std;

int N;
pair<int, int> price_info[50];

int solution() {
	int best_price = 0;
	int maximum_profit = 0;

	sort(price_info, price_info + N);

	for (int i = 0; i < N; i++) {
		int cur_price = price_info[i].first;

		int cur_profit = 0;
		for (int j = i; j < N; j++) {
			cur_profit += max(0, cur_price - price_info[j].second);
		}

		if (cur_profit > maximum_profit) {
			maximum_profit = cur_profit;
			best_price = cur_price;
		}
	}

	return best_price;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> price_info[i].first >> price_info[i].second;
	}

	cout << solution();
}