#include <iostream>
using namespace std;

int N;
int D[10000];
int C[10000];

int solution() {
	int answer = 0;
	for (int X = 0; X < N; X++) {
		int j = 0;
		for (j; j < N; j++) {
			if (X == j) continue;
			if (D[X] > D[j] && C[X] >= C[j]) break;
			if (C[X] > C[j] && D[X] >= D[j]) break;
		}

		if (j == N) answer++;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i] >> C[i];
	}	

	cout << solution();

	return 0;
}
