#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int cardNum[100][100];
int point[100];

void solution() {
	for (int j = 0; j < N; j++)
		sort(cardNum[j], cardNum[j] + M);

	for (int i = 0; i < M; i++) {
		int maxNum = 0;
		for (int j = 0; j < N; j++) 
			maxNum = max(maxNum, cardNum[j][i]);

		for (int j = 0; j < N; j++)
			if (maxNum == cardNum[j][i]) point[j]++;
	}

	int maxNum = 0;
	for (int j = 0; j < N; j++)
		maxNum = max(maxNum, point[j]);

	for (int j = 0; j < N; j++)
		if (maxNum == point[j]) cout << j + 1 << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> cardNum[i][j];

	solution();
}