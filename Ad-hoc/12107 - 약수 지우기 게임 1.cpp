#include <iostream>
using namespace std;

char solution(int n) {
	return (n == 1) ? 'B' : 'A';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << solution(n);
}