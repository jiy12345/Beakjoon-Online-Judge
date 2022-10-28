#include<iostream>
using namespace std;

long long N, R;

long long solution() {
	return N + (2 * R) - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R;

	cout << solution();
}