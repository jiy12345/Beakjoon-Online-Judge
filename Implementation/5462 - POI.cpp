#include<iostream>
#include<vector>
using namespace std;

int N, T, P;
int problemPoint[2000];
int participantState[2000][2000];

void solution() {
	int answer = 1;
	pair<int, int> myPoint = { 0, 0 };

	for (int i = 0; i < T; i++) {
		myPoint.first += participantState[P - 1][i];
		myPoint.second += participantState[P - 1][i] * problemPoint[i];
	}

	for (int i = 0; i < N; i++) {
		if (i == P - 1) continue;
		pair<int, int> curPoint = { 0, 0 };
		for (int j = 0; j < T; j++) {
			curPoint.first += participantState[i][j];
			curPoint.second += participantState[i][j] * problemPoint[j];
		}

		if (curPoint.second > myPoint.second) {
			answer++;
		}
		else if (curPoint.second == myPoint.second) {
			if (curPoint.first > myPoint.first) {
				answer++;
			}
			else if (curPoint.first == myPoint.first) {
				if (i < P - 1) {
					answer++;
				}
			}
		}

	}

	cout << myPoint.second << " " << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> T >> P;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < T; j++) {
			cin >> participantState[i][j];
			if(participantState[i][j] == 0) problemPoint[j]++;
		}
	}

	solution();
}