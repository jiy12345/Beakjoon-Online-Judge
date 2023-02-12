#include<iostream>
using namespace std;

int n;
long long t[36];


long long solution() {
	t[0] = 1;

	for (int i = 1;i <= n;i++) {
		for (int j = 0; j < i;j++) {
			t[i] += t[j] * t[i - j - 1];
		}
	}

	return t[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout << solution();
}