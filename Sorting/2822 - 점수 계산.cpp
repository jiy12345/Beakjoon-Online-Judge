#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> scores;
map<int, int> scoreToNum;

void solution() {
	sort(scores.begin(), scores.end(), greater<int>());

	int sum = 0;
	vector<int> includedNum;
	for (int i = 0; i < 5; i++) {
		sum += scores[i];
		includedNum.push_back(scoreToNum[scores[i]]);
	}

	sort(includedNum.begin(), includedNum.end());
	cout << sum << '\n';
	for (int i = 0; i < 5; i++) cout << includedNum[i] << ' ';
}

int main() {
	scores.resize(8);
	for (int i = 0; i < 8; i++) {
		cin >> scores[i];
		scoreToNum[scores[i]] = i + 1;
	}

	solution();
}