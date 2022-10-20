#include<iostream>
#include<string>
using namespace std;

string input;

void solution() {
	int startIndex = 0;
	int endIndex = 0;
	string output = "";
	
	while (true) {
		startIndex = input.find("What is", startIndex);

		if (startIndex == string::npos) break;

		
		endIndex = input.find_first_of("?.", startIndex);

		if (input[endIndex] == '?') {
			output = "Forty-two" + input.substr(startIndex + 4, endIndex - startIndex - 4) + ".";

			cout << output << '\n';
		}

		startIndex = endIndex;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, input);

	solution();

	return 0;
}