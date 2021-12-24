#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string solution(string *phoneBook, int n) {
	sort(phoneBook, phoneBook + n);

	for (int i = 1; i < n; i++) {
		if (phoneBook[i - 1] == phoneBook[i].substr(0, phoneBook[i - 1].size())) {
			return "NO";
		}
	}

	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string phoneBook[10000];

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> phoneBook[j];
		}

		cout << solution(phoneBook, n) << '\n';
	}

	return 0;
}
