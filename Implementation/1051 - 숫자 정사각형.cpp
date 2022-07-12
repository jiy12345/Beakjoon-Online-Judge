#include<iostream>
using namespace std;

#define MAX 50

int N, M;
string rectangle[MAX];

int solution() {
	int answer = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min(N - i, M - j); k++) {
				if (rectangle[i][j] == rectangle[i + k][j]
					&& rectangle[i + k][j] == rectangle[i][j + k]
					&& rectangle[i][j + k] == rectangle[i + k][j + k]
					) answer = max(answer, (k + 1) * (k + 1));
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> rectangle[i];
	}

	cout << solution();
}
