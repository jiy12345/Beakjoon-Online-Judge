#include<iostream>
using namespace std;

int A[10001];
int N, M;

int solution() {
	int answer = 0;

	int sum = A[0];
	int i = 0;
	int j = 0;

	while (true) {
		while (i <= j) {
			if (sum > M) sum -= A[i++];
			else if (sum < M) sum += A[++j];
			else {
				answer++;
				sum += A[++j];
			}

			cout << "sum: " << sum << endl;
			cout << "i: " << i << endl;
			cout << "j: " << j << endl;

			if (i >= N || j >= N) break;
		}

		if (i >= N || j >= N) break;
		else {
			j++;
			sum = A[i];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution();
}
