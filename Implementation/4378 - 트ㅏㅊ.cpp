#include<iostream>
#include<string>
using namespace std;

string input;
string keyboard[4] = {
	"`1234567890-=",
	"QWERTYUIOP[]\\",
	"ASDFGHJKL;'",
	"ZXCVBNM,./"
};

string solution() {
	string answer = "";
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			answer += ' ';
			continue;
		}
		for (int j = 0; j < 4; j++) {
			int index = 0;
			if ((index = keyboard[j].find(input[i])) != string::npos) {
				answer+= keyboard[j][index - 1];
				break;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (getline(cin, input)) {
		cout << solution() << '\n';
	}
}