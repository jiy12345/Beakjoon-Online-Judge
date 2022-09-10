#include<iostream>
using namespace std;

int n; // n: 5 ~ 20

string names[20];
char Messages[20][19];

void solution() {
	bool isNasty = false;
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			if (Messages[i][j - 1] == 'N') {
				isNasty = true;
				int nasty = (i - j >= 0) ? i - j : i - j + n;
				cout << names[nasty] << " was nasty about " << names[i] << '\n';
			}
	if (isNasty == false) cout << "Nobody was nasty\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int groupNum = 1;
	while (true) {
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> names[i];
			for (int j = 0; j < n - 1; j++) {
				cin >> Messages[i][j];
			}
		}

		cout << "Group " << groupNum++ << '\n';
		solution();
		cout << '\n';
	}
}