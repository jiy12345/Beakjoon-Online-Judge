#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, string> passwords;
int N, M;

void solution() {
	for (int i = 0;i < M;i++) {
		string web_site;
		cin >> web_site;
		cout << passwords[web_site] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0;i < N;i++) {
		string web_site, password;
		cin >> web_site >> password;
		passwords[web_site] = password;
	}

	solution();
}