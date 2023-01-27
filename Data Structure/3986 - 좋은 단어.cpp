#include<iostream>
#include<string>
#include<list>
using namespace std;

int N;
string input_string;

bool solution() {
	int num_brackets = 0;
	int num_square_brackets = 0;

	size_t string_length = input_string.length();
	list<char> char_list;
	for (int i = 0; i < string_length; i++) {
		if (char_list.empty()) {
			char_list.push_back(input_string[i]);
			continue;
		}

		if (input_string[i] == 'A') {
			if (char_list.back() == 'A') {
				char_list.pop_back();
			}
			else {
				char_list.push_back('A');
			}
		}
		if (input_string[i] == 'B') {
			if (char_list.back() == 'B') {
				char_list.pop_back();
			}
			else {
				char_list.push_back('B');
			}
		}
	}

	if (char_list.empty() == false) {
		return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int num_of_good_words = 0;
	for(int i=0;i<N;i++) {
		cin >> input_string;
		num_of_good_words += (solution() ? 1 : 0);
	}

	cout << num_of_good_words;
}