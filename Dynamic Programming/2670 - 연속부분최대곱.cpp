#include<iostream>
using namespace std;

int N;
double max_numbers[10000];
double input_number[10000];

double solution() {
	max_numbers[0] = input_number[0];
	double max_number = max_numbers[0];

	for (int i = 1; i < N; i++) {
		max_numbers[i] = max(input_number[i] * max_numbers[i - 1], input_number[i]);
		max_number = max(max_numbers[i], max_number);
	}

	return max_number;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input_number[i];
	}

	cout.setf(ios::fixed);
	cout.precision(3);
	cout << solution();
}