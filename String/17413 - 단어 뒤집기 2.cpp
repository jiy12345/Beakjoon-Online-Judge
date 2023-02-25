#include<iostream>
#include<algorithm>
using namespace std;

void solution() {
	char character;
	string word = "";
	bool is_tag = false;
	while (true) {
		character = getchar();
		if (is_tag == false) {
			if (character == ' ' || character == '\n') {
				reverse(word.begin(), word.end());
				cout << word << ' ';
				word = "";
			}
			else if (character == '<') {
				is_tag = true;
				reverse(word.begin(), word.end());
				cout << word;
				word = "<";
			}
			else {
				word += character;
			}
		}
		else {
			if (character == '>') {
				is_tag = false;
				cout << word << '>';
				word = "";
			}
			else {
				word += character;
			}
		}
		if (character == '\n')
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}