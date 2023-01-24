#include<iostream>
#include<string>
#include<list>
using namespace std;

string input_string;

string solution() {
	int num_brackets = 0;
	int num_square_brackets = 0;

	size_t string_length = input_string.length();
	list<char> bracket_list;
	for (int i = 0; i < string_length; i++) {
		if (input_string[i] == '(') {
			bracket_list.push_back('(');
		}
		if (input_string[i] == ')') {
			if (bracket_list.empty() == false && bracket_list.back() == '(') {
				bracket_list.pop_back();
			}
			else {
				return "no";
			}
		}
		if (input_string[i] == '[') {
			bracket_list.push_back('[');
		}
		if (input_string[i] == ']') {
			if (bracket_list.empty() == false && bracket_list.back() == '[') {
				bracket_list.pop_back();
			}
			else {
				return "no";
			}
		}
	}

	if (bracket_list.empty() == false) {
		return "no";
	}

	return "yes";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		getline(cin, input_string);
		if (input_string == ".") {
			break;
		}
		cout << solution() << '\n';
	}
}