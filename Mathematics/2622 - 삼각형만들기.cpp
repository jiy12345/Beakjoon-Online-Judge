#include<iostream>
using namespace std;

int N;

int solution() {
	int answer = 0;

	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N - i; j++) {
			int k = N - i - j;
			if (k < j) break;

			if (k < i + j) answer++;
		}

	return answer;
}

int main() {
	cin >> N;
	cout << solution();
}