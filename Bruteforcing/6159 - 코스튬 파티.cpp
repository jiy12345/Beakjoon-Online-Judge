#include<iostream>
using namespace std;

int S, N;
int weightOfCow[20000];

int solution() {
	int answer = 0;

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (weightOfCow[i] + weightOfCow[j] <= S) answer++;
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> weightOfCow[i];
	}

	cout << solution();
}

