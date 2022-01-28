#include<iostream>
using namespace std;

int M, N;
int x, y;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	
	int n;

	while (b != 0) {
		n = a % b;
		
		a = b;
		b = n;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int solution() {
	// y == N일 경우 y가 0으로 표현되므로 0으로 설정!
	if (y == N) y = 0;
	int maxNum = lcm(M, N);

	for (int i = x; i <= maxNum; i += M)
		if (i % N == y) return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;

		cout << solution() << '\n';
	}

}
