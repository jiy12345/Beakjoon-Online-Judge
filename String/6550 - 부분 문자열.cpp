#include <iostream>
#include <string>
using namespace std;

string s, t;

bool solution(){
	bool answer = false;
	int j = 0;
	for (int i = 0; i < t.length(); i++) {
		if (s[j] == t[i]) {
			j++;
		}
		if (j == s.length()) {
			answer = true;
			break;
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> s >> t) {
		if (solution()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}