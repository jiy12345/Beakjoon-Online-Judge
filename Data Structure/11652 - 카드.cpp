#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;

int N;
unordered_map<long long, int> num_of_card;

long long solution() {
	int max_num = 0;
	long long answer = INT64_MAX;
	for (const auto &card_info : num_of_card) {
		if (max_num < card_info.second) {
			max_num = card_info.second;
			answer = card_info.first;
		}
		else if (max_num == card_info.second) {
			if (answer > card_info.first) {
				max_num = card_info.second;
				answer = card_info.first;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		long long card_number;
		cin >> card_number;
		num_of_card[card_number]++;
	}

	cout << solution();
}