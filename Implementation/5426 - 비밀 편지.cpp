#include <iostream>
#include <cmath>
using namespace std;

int T;
string input;

string solution() {
	string answer = "";

	int squareLength = sqrt(input.length());

	for (int j = squareLength - 1; j >= 0; j--) {
		for (int i = 0; i < squareLength; i++) {
			answer += input[i * squareLength + j];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> input;
		cout << solution() << '\n';
	}

	return 0;
}