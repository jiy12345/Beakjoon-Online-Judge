#include<iostream>
#include<map>
using namespace std;

#define MAX 10000
#define NUM_NOTES 12
#define NUM_WHITE_NOTES 7
#define BLACK_NOTE 'X'

char piano[NUM_NOTES] = { 'A', 'X', 'B', 'C', 'X', 'D', 'X', 'E', 'F', 'X', 'G', 'X' };

int n;
int score[MAX];

void solution() {
	for (int i = 0; i < NUM_NOTES; i++) {
		if (piano[i] == BLACK_NOTE) continue;
		char startNote = piano[i];
		char endNote;
		
		int curNote = i;

		int j = 0;
		for (j; j < n; j++) {
			curNote += score[j];
			if (curNote < 0) curNote = NUM_NOTES + curNote;
			curNote %= NUM_NOTES;
			if (piano[curNote] == BLACK_NOTE) break;
		}

		if (j == n) {
			endNote = piano[curNote];
			cout << startNote << " " << endNote << '\n';
		}
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> score[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solution();

	return 0;
}