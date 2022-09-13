#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string input;

string solution() {
	int strSize = input.size();
	string answer = input;

	for (int i = 1; i < strSize; i++) {
		for (int j = i + 1; j < strSize; j++) {
			string subStrs[3];
			subStrs[0] = input.substr(0, i);
			subStrs[1] = input.substr(i, j - i);
			subStrs[2] = input.substr(j);

			for (int k = 0; k < 3; k++) {
				reverse(subStrs[k].begin(), subStrs[k].end());
			}

			answer = min(answer, subStrs[0] + subStrs[1] + subStrs[2]);
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input;
	cout << solution();
}
