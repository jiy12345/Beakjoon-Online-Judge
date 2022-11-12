#include<iostream>
#include<limits.h>
using namespace std;

int N, M;
int A[1000001];
int B[1000001];

void solution() {
	A[N] = INT_MAX;
	B[M] = INT_MAX;

	int A_index = 0;
	int B_index = 0;

	while (true) {
		cout << ((A[A_index] < B[B_index]) ? A[A_index++] : B[B_index++]) << ' ';

		if (A_index == N && B_index == M)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	solution();

	return 0;
}