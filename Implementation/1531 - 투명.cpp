#include<iostream>
using namespace std;

int painting[101][101];
int N, M;

int solution() {
	int answer = 0;
	int start_i, start_j, end_i, end_j;
	for (int i = 0; i < N; i++) {
		cin >> start_j >> start_i >> end_j >> end_i;

		for (int i = start_i; i <= end_i; i++)
			for (int j = start_j; j <= end_j; j++)
				painting[i][j]++;
	}

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if (painting[i][j] > M) answer++;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	cout << solution();

	return 0;
}