#include <iostream>
#include <string>
using namespace std;

string password;
string vowel = "aeiou";

bool solution() {
	bool answer = true;

	bool isVowelAppeared = false;

	int vowelCnt = 0;
	int consonantCnt = 0;
	for (int i = 0; i < password.size(); i++) {
		if (vowel.find(password[i]) != string::npos) {
			isVowelAppeared = true;
			if (consonantCnt != 0) consonantCnt = 0;
			vowelCnt++;
		}
		else {
			if (vowelCnt != 0) vowelCnt = 0;
			consonantCnt++;
		}

		if (vowelCnt == 3 || consonantCnt == 3) return false;

		if (i == 0) continue;
		if (password[i - 1] == password[i])
			if (password[i] != 'e' && password[i] != 'o') return false;
	}

	if (isVowelAppeared == false) answer = false;
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> password;
		if (password == "end") break;

		cout << "<" << password << ">" << (solution() ? " is acceptable." : " is not acceptable.") << '\n';
	}
}