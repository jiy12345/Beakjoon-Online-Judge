#include<iostream>
using namespace std;

unsigned int S;

int solution() {
	long long curSum = 1;
	int N = 1;

	while (true) {
		curSum += (N + 1);
		if (curSum > S) break;
		N++;
	}

	return N;
}

int main() {
	cin >> S;

	cout << solution();
}