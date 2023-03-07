#include<iostream>
#include<algorithm>
using namespace std;

int alphabets[26];
string input_string;

string solution() {
	int string_length = input_string.length();

	for (int i = 0;i < string_length;i++) {
		alphabets[input_string[i] - 'A']++;
	}

	char center_alpha = 0;
	string palindrome = "";
	for (int i = 0;i < 26;i++) {
		if (alphabets[i] % 2 == 1) {
			if (center_alpha != 0) {
				return "I'm Sorry Hansoo";
			}

			center_alpha = i + 'A';
		}

		for (int j = 0;j < alphabets[i] / 2;j++) {
			palindrome += i + 'A';
		}
	}

	string front_palindrome = palindrome;

	if (center_alpha != 0) {
		palindrome += center_alpha;
	}

	reverse(palindrome.begin(), palindrome.end());
	palindrome = front_palindrome + palindrome;

	return palindrome;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input_string;

	cout << solution();
}