#include<iostream>
#include<algorithm>
using namespace std;

int T;
int k;
string words[100];

bool isPalindrome(const string& curString) {
	bool isPal = true;
	int length = curString.length();
	for (int i = 0; i < length / 2; i++)
		if (curString[i] != curString[length - 1 - i]) {
			isPal = false;
			break;
		}

	return isPal;
}

string solution() {
	string answer = "0";

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (i == j) continue;
			string curString = words[i] + words[j];
			if (isPalindrome(curString))
				return curString;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;

		for (int j = 0; j < k; j++)
			cin >> words[j];

		cout << solution() << '\n';
	}

	return 0;
}