#include<iostream>
#include<algorithm>
using namespace std;

int N;
int number_array[50];

int solution() {
	sort(number_array, number_array + N);

	int min_num_required = 5;

	for (int i = 0; i < N; i++) {
		int cur_start_number = number_array[i];
		int num_cur_required = 0;
		int next_index = i + 1;
		for (int j = 1; j < 5; j++) {
			if (number_array[next_index] == cur_start_number + j) {
				next_index++;
			}
			else {
				num_cur_required++;
			}
		}
		

		min_num_required = min(min_num_required, num_cur_required);
		if (min_num_required == 0) break;
	}

	return min_num_required;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number_array[i];
	}

	cout << solution();
}