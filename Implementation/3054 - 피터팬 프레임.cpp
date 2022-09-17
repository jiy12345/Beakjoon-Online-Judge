#include <iostream>
#include <string>
using namespace std;

string str;
string frames[5];

void solution() {
	frames[0] = "..#..";
	for (int i = 1; i < str.length(); i++)
		if (i % 3 != 2)
			frames[0] += ".#..";
		else
			frames[0] += ".*..";

	frames[1] = ".#.#.";
	for (int i = 1; i < str.length(); i++)
		if (i % 3 != 2)
			frames[1] += "#.#.";
		else
			frames[1] += "*.*.";

	frames[2] = "#.";
	frames[2] += str[0];
	frames[2] += ".#";
	for (int i = 1; i < str.length(); i++)
		if (i % 3 == 1) {
			frames[2] += ".";
			frames[2] += str[i];
			if (i == str.length() - 1)
				frames[2] += ".#";
			else
				frames[2] += ".*";
		}
		else if (i % 3 == 2) {
			frames[2] += ".";
			frames[2] += str[i];
			frames[2] += ".*";
		}
		else {
			frames[2] += ".";
			frames[2] += str[i];
			frames[2] += ".#";
		}

	frames[3] = frames[1];
	frames[4] = frames[0];

	for (int i = 0; i < 5; i++)
		cout << frames[i] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	solution();

	return 0;
}