#include <iostream>
using namespace std;

long long N, B;
int A[5][5];
int result[5][5];

void matrix_multi(int A1[5][5], int A2[5][5]) {
	int temp[5][5];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < N; k++)
				temp[i][j] += (A1[i][k] * A2[k][j]);
			temp[i][j] %= 1000;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A1[i][j] = temp[i][j];
}

void solution() {
	while (B) {
		if (B % 2 == 1) {
			matrix_multi(result, A);
		}
		matrix_multi(A, A);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		result[i][i] = 1;
	}

	solution();

	return 0;
}