#include<iostream>
#include<cstdlib>
using namespace std;

int N, M;
int paper[102][102];

int solution() {
	int answer = 0;

	// 위, 아래면
	answer += 2 * (M * N);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			answer += abs(paper[i][j] - paper[i][j + 1]);
		}
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			answer += abs(paper[j][i] - paper[j+ 1][i]);
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> paper[i][j];
		}
	}

	cout << solution();

	return 0;
}
