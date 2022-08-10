#include<iostream>
using namespace std;

string solution() {
	char ch;
	string answer = "";

	int cnt = 0;
	while (true) {
		ch = getchar();
		if (ch == 'X') {
			cnt++;
			if (cnt == 4) {
				answer += "AAAA";
				cnt = 0;
			}
		}
		else {
			if (cnt == 2)		answer += "BB";
			else if (cnt == 4)  answer += "AAAA";
			else if (cnt == 0);
			else				return "-1";

			if (ch == '\n') break;

			answer += ".";
			cnt = 0;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << solution();
}