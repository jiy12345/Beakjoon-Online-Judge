#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, char> binToOct = {
	{"000", '0'},
	{"001", '1'},
	{"010", '2'},
	{"011", '3'},
	{"100", '4'},
	{"101", '5'},
	{"110", '6'},
	{"111", '7'}
};

void solution(string input) {
	int i = 0;

	int len = input.length();
	if (len % 3 == 1) {
		cout << binToOct["00" + to_string(input[0] - '0')];
		i = 1;
	}
	else if (len % 3 == 2) {
		cout << binToOct["0" + to_string(input[0] - '0') + to_string(input[1] - '0')];
		i = 2;
	}

	for (i; i < len; i += 3) {
		string bin = to_string(input[i] - '0') + to_string(input[i + 1] - '0') + to_string(input[i + 2] - '0');
		cout << binToOct[bin];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;

	cin >> input;

	solution(input);

	return 0;
}