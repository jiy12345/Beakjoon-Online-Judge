#include<iostream>
#include<vector>
using namespace std;

int input[3000];
int n;

string solution() {
	string answer = "Jolly";
	vector<bool> isAppeared(n + 1);
	int i;
	for (i = 1; i < n; i++) {
		int curNum = abs(input[i] - input[i - 1]);
		if (isAppeared[curNum] == true || curNum >= n) break;
		isAppeared[curNum] = true;
	}

	if (i != n) answer = "Not jolly";
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (cin.eof() != true) {
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		cout << solution() << '\n';

		cin >> n;
	}
}