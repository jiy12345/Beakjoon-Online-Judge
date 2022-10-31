#include<vector>
#include<iostream>
using namespace std;

long long fibonacci[90] = { 0, };

int N;

long long fibo(int n) {
	if (fibonacci[n] != 0) return fibonacci[n];
	fibonacci[0] = 1;
	fibonacci[1] = 1;

	for (int i = 2; i < n; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	return fibonacci[n];
}

long long solution() {
	return 4 * fibo(N + 2) + 2 * fibo(N + 1);
}

int main() {
	cin >> N;
	cout << solution();
}