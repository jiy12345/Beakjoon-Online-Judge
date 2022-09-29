#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string input;

bool isPalindrome(string cur_num) {
	string cur_num_not_reversed = cur_num;
	reverse(cur_num.begin(), cur_num.end());
	string cur_num_reversed = cur_num;

	if (cur_num_not_reversed == cur_num_reversed) {
		return true;
	}
	else {
		return false;
	}
}

void getNextStrNum(string& s)
{
	int r = s.length() - 1;
	while (s[r] == '9')
		s[r] = '0', r--;
	s[r]++;
}

int solution() {
	int startNum = stoi(input);
	while(true) {
		if (isPalindrome(input)) {
			break;
		}
		getNextStrNum(input);
	}
	
	return stoi(input) - startNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> input;
		if (input == "0") break;
		cout << solution() << '\n';
	}

	return 0;
}