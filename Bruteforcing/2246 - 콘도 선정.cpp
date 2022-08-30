#include <iostream>
using namespace std;

int N;
int D[10000];
int C[10000];

int solution() {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int j = 0;
		for (j; j < N; j++) {
			if (D[i] > D[j] && C[i] > C[j]) break;
			if (C[i] > C[j] && D[i] > D[j]) break;
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

	for (int i = 0; i < N; i++)
		

	cout << solution();

	return 0;
}