#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A, P;
vector<long long> num_sequence;

int solution() {
	num_sequence.push_back(A);

	while (true) {
		int temp_num = num_sequence.back();
		int cur_num = 0;

		while (true) {
			int cur_digit = temp_num % 10;
			int cur_product = 1;

			for (int i = 0; i < P; i++) {
				cur_product *= cur_digit;
			}

			cur_num += cur_product;

			temp_num /= 10;
			if (temp_num == 0) {
				break;
			}
		}

		auto it_begin_cycle = find(num_sequence.begin(), num_sequence.end(), cur_num);
		if (it_begin_cycle != num_sequence.end()) {
			return distance(num_sequence.begin(), it_begin_cycle);
		}

		num_sequence.push_back(cur_num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> P;

	cout << solution();
}