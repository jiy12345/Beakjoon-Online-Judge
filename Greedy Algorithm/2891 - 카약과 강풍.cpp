#include<iostream>
using namespace std;

int N, S, R;

int numOfKayak[12];

int solution() {
	for (int i = 0; i < S; i++) {
		int broken;
		cin >> broken;
		numOfKayak[broken]--;
	}

	for (int i = 0; i < R; i++) {
		int extra;
		cin >> extra;
		numOfKayak[extra]++;
	}

	for (int i = 1; i <= 10; i++) {
		if (numOfKayak[i] == -1) {
			if (numOfKayak[i - 1] == 1) {
				numOfKayak[i]++;
				numOfKayak[i - 1]--;
				continue;
			}
			if (numOfKayak[i + 1] == 1) {
				numOfKayak[i]++;
				numOfKayak[i + 1]--;
				continue;
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
		if (numOfKayak[i] == -1) answer++;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> R;

	cout << solution();
}