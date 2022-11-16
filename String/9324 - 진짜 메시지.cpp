#include<iostream>
#include<cstring>
using namespace std;

int M;
string input;
int charNum[26];

string solution() {
	string answer = "OK";

	int length = input.size();
	for (int i = 0; i < length; i++) {
		char prevChar, curChar;
		curChar = input[i];

		charNum[curChar - 'A']++;
		if (charNum[curChar - 'A'] == 3) {
			i++;
			prevChar = curChar;
			if (i >= length) {
				answer = "FAKE";
				break;
			}
			curChar = input[i];
			if (prevChar != curChar) {
				answer = "FAKE";
				break;
			}
			charNum[curChar - 'A'] = 0;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> input;
		cout << solution() << '\n';
		memset(charNum, 0, sizeof(charNum));
	}
}