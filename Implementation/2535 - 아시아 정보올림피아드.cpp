#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int N;

vector<int> studentsInfo[100];

void solution() {
	sort(&studentsInfo[0], &studentsInfo[N]);
	
	vector<vector<int>> winners;
	map<int, int> numOfWinners;

	for (int i = N - 1; i > 0; i--) {
		if (numOfWinners[studentsInfo[i][1]] < 2) {
			numOfWinners[studentsInfo[i][1]]++;
			winners.push_back(studentsInfo[i]);
		}

		if (winners.size() == 3) break;
	}

	for (int i = 0; i < 3; i++) {
		cout << winners[i][1] << " ";
		cout << winners[i][2];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		studentsInfo[i].resize(3);
		cin >> studentsInfo[i][1];
		cin >> studentsInfo[i][2];
		cin >> studentsInfo[i][0];
	}

	solution();

	return 0;
}