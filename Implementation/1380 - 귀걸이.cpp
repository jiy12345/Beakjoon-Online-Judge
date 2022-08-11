#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n;
string names[100];
char isRecieved[100];

bool input() {
	cin >> n;
	
	if (n == 0) return false;
	cin.ignore();
	for (int i = 0; i < n; i++)
		getline(cin, names[i]);

	return true;
}

void solution(int cnt) {
	memset(isRecieved, 0x00, sizeof(isRecieved));
	
	for (int i = 0; i < 2 * n - 1; i++) {
		int studentNum;
		char alpha;

		cin >> studentNum >> alpha;

		isRecieved[studentNum - 1]++;
	}

	for (int i = 0; i < n; i++)
		if (isRecieved[i] == 1) {
			cout << cnt << " " << names[i] << '\n';
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 1;
	while (true) {
		if (input() == false) break;

		solution(cnt);
		cnt++;
	}
}