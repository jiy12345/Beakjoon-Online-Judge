#include<iostream>
using namespace std;

int N, M, K;

int A[100][100];
int B[100][100];
int result[100][100];

void solution() {
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++)
			for (int k = 0; k < M; k++)
				result[i][j] += A[i][k] * B[k][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	
	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	solution();

	return 0;
}