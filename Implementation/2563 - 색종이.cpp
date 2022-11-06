#include<iostream>
using namespace std;

int n;
bool drawingPaper[100][100];

int solution() {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x + 10; j++)
			for (int k = y; k < y + 10; k++)
				drawingPaper[j][k] = true;
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			answer += (drawingPaper[i][j] == true) ? 1 : 0;

	return answer;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	cout << solution();
}