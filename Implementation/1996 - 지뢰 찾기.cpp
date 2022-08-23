#include<iostream>
using namespace std;

#define MAX 1000

int N;
char inputMap[MAX][MAX];
int answerMap[MAX][MAX];

int di[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dj[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline int isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void solution() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (inputMap[i][j] != '.') {
				answerMap[i][j] = -1;
				for (int k = 0; k < 8; k++) {
					int cur_i = i + di[k];
					int cur_j = j + dj[k];
					int curNum = inputMap[i][j] - '0';
					if (isInRange(cur_i, cur_j) && inputMap[cur_i][cur_j] == '.') {
						answerMap[cur_i][cur_j] += curNum;
					}
				}
			}
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char charToPrint;
			if (answerMap[i][j] == -1)
				charToPrint = '*';
			else if (answerMap[i][j] >= 10)
				charToPrint = 'M';
			else
				charToPrint = answerMap[i][j] + '0';
			cout << charToPrint;
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> inputMap[i][j];

	solution();
}