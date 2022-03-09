#include<iostream>
using namespace std;

int A[100001];
int N, S;

int solution() {
	int answer = N + 1;

	int sum = A[0];
	int i = 0;
	int j = 0;

	while (true) {
		if (sum >= S) {
			// 하나의 수가 S 이상일 경우
			if (i == j)  return 1;
			answer = min(answer, j - i + 1);
			sum -= A[i++];
		}
		else {
			sum += A[++j];
		}

		if (i >= N || j >= N) break;
	}

	if (answer == N + 1) answer = 0;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution();
}
