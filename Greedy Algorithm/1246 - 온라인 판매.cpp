#include<iostream>
#include<algorithm>
using namespace std;

int number_of_eggs, number_of_customers;
int payable_price[1000];

void solution() {
	sort(payable_price, payable_price + number_of_customers, greater<>());
	
	int max_profit = 0;
	int set_price = 0;
	for (int number_of_sold_eggs = 1; number_of_sold_eggs <= number_of_eggs; number_of_sold_eggs++) {
		if (max_profit < number_of_sold_eggs * payable_price[number_of_sold_eggs - 1]) {
			set_price = payable_price[number_of_sold_eggs - 1];
			max_profit = number_of_sold_eggs * set_price;
		}
	}

	cout << set_price << " " << max_profit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> number_of_eggs >> number_of_customers;
	for (int i = 0; i < number_of_customers; i++) {
		cin >> payable_price[i];
	}
	solution();
}
