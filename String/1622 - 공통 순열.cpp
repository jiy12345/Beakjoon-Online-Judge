#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string a, b;
int a_alpha[26];
int b_alpha[26];

string solution() {
	string answer = "";
	memset(a_alpha, 0, sizeof(a_alpha));
	memset(b_alpha, 0, sizeof(b_alpha));
	for (int i = 0; i < a.length(); i++) {
		a_alpha[a[i] - 'a']++;
	}
	for (int i = 0; i < b.length(); i++) {
		b_alpha[b[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		int num_of_alpha = min(a_alpha[i], b_alpha[i]);
		for (int j = 0; j < num_of_alpha; j++) {
			answer += ('a' + i);
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (getline(cin, a)) {
		getline(cin, b);
		cout << solution() << '\n';
	}
}