#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int n;
string input;
int alpha[26];

string solution(int index) {
	memset(alpha, 0, sizeof(alpha));

	for (int i = 0; i < input.size(); i++) {
		char curChar = input[i];
		if (65 <= curChar && curChar <= 90) {
			curChar = towlower(curChar);
		}
		else if (97 <= curChar && curChar <= 122){}
		else {
			continue;
		}

		alpha[curChar - 97]++;
	}

	int minNum = *min_element(&alpha[0], &alpha[26]);
	
	cout << "Case " << index << ": ";
	switch (minNum) {
	case 1: 
		return "Pangram!\n";
		break;
	case 2:
		return "Double pangram!!\n";
		break;
	case 3:
		return "Triple pangram!!!\n";
		break;
	default:
		return "Not a pangram\n";
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, input);
		cout << solution(i + 1);
	}
}