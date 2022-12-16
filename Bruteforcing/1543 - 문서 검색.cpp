#include<iostream>
#include<string>
using namespace std;

string input_string;
string pattern_string;

int solution() {
	if (input_string.length() < pattern_string.length())
		return 0;

	int num_of_patterns_in_string = 0;

	for (int i = 0; i < input_string.length() - pattern_string.length() + 1; i++) {
		int j;
		for (j = 0; j < pattern_string.length(); j++) {
			if (input_string[i + j] != pattern_string[j]) {
				break;
			}
		}

		if (j == pattern_string.length()) {
			num_of_patterns_in_string++;
			i += pattern_string.length() - 1;
		}
	}

	return num_of_patterns_in_string;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, input_string);
	getline(cin, pattern_string);

	cout << solution();
}