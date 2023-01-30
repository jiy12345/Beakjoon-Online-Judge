#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string S;

void solution() {
	int string_length = S.length();
	
	vector<string> suffixes(string_length);

	for (int i = 0;i < string_length;i++) {
		suffixes[i] = S.substr(i);
	}

	sort(suffixes.begin(), suffixes.end());

	for (auto suffix : suffixes) {
		cout << suffix << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S;

	solution();
}