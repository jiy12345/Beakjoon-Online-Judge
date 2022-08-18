#include<iostream>
#include<string>
using namespace std;

string X;

void solution() {
	int cnt = 0;
	int checkNum = 0;

	if (X.length() == 1) {
		checkNum = stoi(X);
	}
	else {
		cnt++;
		for (char num : X) {
			checkNum += (num - '0');
		}
	}

	while (true) {
		if (checkNum < 10) break;

		int temp = checkNum;
		checkNum = 0;
		while (true) {
			if (temp == 0) break;

			checkNum += (temp % 10);
			temp /= 10;
		}
		cnt++;
	}

	cout << cnt << '\n';
	cout << ((checkNum % 3 == 0) ? "YES" : "NO");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X;

	solution();
}
