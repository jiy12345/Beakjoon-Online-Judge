#include<iostream>
using namespace std;

int N;

int solution() {
	if (N == 1) return 1;
	int max_length = 2;
	int cur_length = 1;

	int num_of_same_num = 1;

	int prev_num = 0;
	int cur_num = 0;

	cin >> prev_num;
	cin >> cur_num;
	bool is_increasing = (cur_num > prev_num) ? true : false;
	prev_num = cur_num;

	for (int i = 2; i < N; i++) {
		cin >> cur_num;
		
		if (prev_num == cur_num) {
			num_of_same_num++;
		}
		else {
			cur_length += num_of_same_num;
			if (is_increasing && cur_num < prev_num) {
				max_length = max(max_length, cur_length);
				cur_length = num_of_same_num;
				is_increasing = false;
			}

			if (!is_increasing && cur_num > prev_num) {
				max_length = max(max_length, cur_length);
				cur_length = num_of_same_num;
				is_increasing = true;
			}
			
			num_of_same_num = 1;
		}

		prev_num = cur_num;
	}

	cur_length += num_of_same_num;
	max_length = max(max_length, cur_length);

	return max_length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution();
}