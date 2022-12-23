#include<iostream>
using namespace std;

long long N;
bool bit_mask[40];

long long solution() {
	long long target_number = 0;

	int cur_index = 0;
	while (N != 0) {
		if (N % 2 == 1) bit_mask[cur_index] = true;
		N /= 2;
		cur_index++;
	}

	long long power_of_three = 1;

	for (int i = 0; i < cur_index; i++) {
		target_number += (bit_mask[i] == true) ? power_of_three : 0;
		power_of_three *= 3;
	}

	return target_number;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solution();
}
