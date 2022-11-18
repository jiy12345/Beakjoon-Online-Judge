#include<iostream>
using namespace std;

int N;

int solution() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		int interval, time, cycle;

		cin >> interval >> time;
		cycle = time + interval;

		int timeInCycle = answer % cycle;
		answer++;
		if (timeInCycle < time)
			answer += (time - timeInCycle);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solution();
}