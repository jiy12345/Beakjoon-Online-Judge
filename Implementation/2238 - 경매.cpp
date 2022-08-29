#include <iostream>
using namespace std;

int U, N;
string namesFirst[10001];
int numOfPeple[10001];

void solution() {
	string S;
	int P;

	for (int i = 0; i < N; i++) {
		cin >> S >> P;

		if (numOfPeple[P] == 0) namesFirst[P] = S;
		numOfPeple[P]++;
	}

	int minIndex = 0;
	int minNum   = N + 1;
	for (int i = 1; i <= U; i++) {
		if (numOfPeple[i] == 0) continue;
		if (minNum > numOfPeple[i]) {
			minNum = numOfPeple[i];
			minIndex = i;
		}
	}

	cout << namesFirst[minIndex] << " " << minIndex;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> U >> N;

	solution();

	return 0;
}