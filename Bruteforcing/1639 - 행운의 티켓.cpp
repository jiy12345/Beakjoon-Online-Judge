#include<iostream>
using namespace std;

string input_number;

int solution() {
	int answer = 0;

	for (int ticket_number_length = 2; ticket_number_length <= input_number.length(); ticket_number_length+=2) {
		for (int start_index = 0; start_index <= input_number.length() - ticket_number_length; start_index++) {
			int end_index = start_index + ticket_number_length;
			int left_sum = 0;
			int right_sum = 0;
			
			for (int index = 0; index < ticket_number_length / 2; index++) {
				left_sum += (input_number[start_index + index] - '0');
				right_sum += (input_number[end_index - index - 1] - '0');
			}

			if (right_sum == left_sum) {
				answer = ticket_number_length;
				break;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input_number;
	cout << solution();
}