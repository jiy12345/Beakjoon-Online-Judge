#include <iostream>
using namespace std;

long long N;

void solution() {
	long long K = 1;

	while (K < N) K = K * 2 + 1;
	
	if (K == N) cout << 1 << '\n' << N;
	else cout << 2 << '\n' << (K ^ N) << '\n' << N;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();
}