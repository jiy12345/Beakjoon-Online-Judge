#include<iostream>
using namespace std;

int numPrimeFactor(int n, int primeFactor) {
	int numPrimeFactor = 0;

	for (long long i = primeFactor; n / i >= 1; i *= primeFactor) {
		numPrimeFactor += n / i;
	}

	return numPrimeFactor;
}

int solution(int n, int m) {
	int numOfFive = 0;
	int numOfTwo = 0;

	numOfFive = numPrimeFactor(n, 5) - numPrimeFactor(n - m, 5) - numPrimeFactor(m, 5);
	numOfTwo = numPrimeFactor(n, 2) - numPrimeFactor(n - m, 2) - numPrimeFactor(m, 2);

	return min(numOfTwo, numOfFive);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	cout << solution(n, m);
}
