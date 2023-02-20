#include<iostream>
using namespace std;

int N;
int prices[100000];
int distances[100000];

long long solution() {
	long long cur_min_price = prices[0];
	long long min_price = 0;
	long long cur_oil_price = 0;

	for (int i = 1;i < N;i++) {
		cur_oil_price += cur_min_price * distances[i - 1];

		if (prices[i] < cur_min_price) {
			cur_min_price = prices[i];
			min_price += cur_oil_price;
			cur_oil_price = 0;
		}
	}

	min_price += cur_oil_price;

	return min_price;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0;i < N - 1;i++) {
		cin >> distances[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> prices[i];
	}
	
	cout << solution();
}