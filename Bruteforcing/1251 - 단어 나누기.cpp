#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string input;

string solution() {
	int N = input.size();

	string answer(N, 'z');

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			string firstPart = input.substr(0, i);
			string secondPart = input.substr(i, j - i);
			string thirdPart = input.substr(j);

			reverse(firstPart.begin(), firstPart.end());
			reverse(secondPart.begin(), secondPart.end());
			reverse(thirdPart.begin(), thirdPart.end());

			string curString = firstPart + secondPart + thirdPart;

			answer = (answer < curString) ? answer : curString;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input;

	cout << solution();

	return 0;
}
