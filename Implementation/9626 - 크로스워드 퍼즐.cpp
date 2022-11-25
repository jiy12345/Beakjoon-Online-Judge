#include <iostream>
using namespace std;

int M, N;
int U, L, R, D;

char crossWord[10][10];

void solution() {
	int i = 0;
	for (i; i < U; i++) {
		for (int j = 0; j < N + R + L; j++)
			cout << (((i + j) % 2 == 0) ? '#' : '.');
		cout << '\n';
	}

	for (i; i < M + U; i++) {
		for (int j = 0; j < L; j++)
			cout << (((i + j) % 2 == 0) ? '#' : '.');

		for (int j = L; j < L + N; j++)
			cout << crossWord[i - U][j - L];

		for (int j = L + N; j < L + N + R; j++)
			cout << (((i + j) % 2 == 0) ? '#' : '.');

		cout << '\n';
	}

	for (i; i < M + U + D; i++) {
		for (int j = 0; j < N + R + L; j++)
			cout << (((i + j) % 2 == 0) ? '#' : '.');
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	cin >> U >> L >> R >> D;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> crossWord[i][j];

	solution();
}