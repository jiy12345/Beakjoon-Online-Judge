#include<iostream>
#include<vector>
using namespace std;

int N;
int feeling[100000];
bool buy_flower[100000];

int solution() {
	int day_buy_flower = 0;

	int cur_feeling_bad_length = 0;
	int max_length = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (feeling[i] < 0) {
			cur_feeling_bad_length++;
			continue;
		}

		for (int j = 0; j < cur_feeling_bad_length * 2; j++) {
			if (i - j < 0)
				break;
			buy_flower[i - j] = true;
		}

		max_length = max(max_length, cur_feeling_bad_length);
		cur_feeling_bad_length = 0;
	}

	cur_feeling_bad_length = 0;
	int max_new_day = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (feeling[i] < 0) {
			cur_feeling_bad_length++;
			continue;
		}

		if (cur_feeling_bad_length == max_length) {
			int cur_new_day = 0;
			for (int j = 0; j < cur_feeling_bad_length * 3; j++) {
				if (i - j < 0)
					break;
				if (buy_flower[i - j] == false)
					cur_new_day++;
			}

			max_new_day = max(max_new_day, cur_new_day);
		}

		cur_feeling_bad_length = 0;
	}

	for (int i = 0; i < N; i++) {
		if (buy_flower[i] == true) {
			day_buy_flower++;
		}
	}
	day_buy_flower += max_new_day;

	return day_buy_flower;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> feeling[i];
	}

	cout << solution();
}