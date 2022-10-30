#include<iostream>
using namespace std;

int N;

void solution() {
	string pokeName = "";
	int maxNum = 0;
	int totalNum = 0;

	for (int i = 0; i < N; i++) {
		string curName;
		int candyNeeded, numOfCandy;
		cin >> curName >> candyNeeded >> numOfCandy;

		int curNumEvo = numOfCandy / (candyNeeded - 2);
		if (numOfCandy % (candyNeeded - 2) <= 1 && curNumEvo != 0)
			curNumEvo--;

		if (maxNum < curNumEvo) {
			pokeName = curName;
			maxNum = curNumEvo;
		}
		totalNum += curNumEvo;
	}

	cout << totalNum << '\n' << pokeName;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();

	return 0;
}