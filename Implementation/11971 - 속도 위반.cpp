#include<iostream>
using namespace std;

int N, M;
int speedLimit[100];
int actualSpeed[100];

int solution() {
	int start = 0;
	int end = 0;
	int speed, dist;
	for (int i = 0; i < N; i++) {
		cin >> dist >> speed;

		end = start + dist;

		for (int j = start; j < end; j++)
			speedLimit[j] = speed;
		start = end;
	}

	start = 0;
	for (int i = 0; i < M; i++) {
		cin >> dist >> speed;

		end = start + dist;

		for (int j = start; j < end; j++)
			actualSpeed[j] = speed;
		start = end;
	}

	int answer = 0;
	for (int i = 0; i < 100; i++)
		answer = max(answer, actualSpeed[i] - speedLimit[i]);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	cout << solution();
}
