#include<iostream>
using namespace std;

int n, k;
int coefs_divided[10001];

void solution() {
	for (int i = 0; i < n + 1; i++) {
		cin >> coefs_divided[i];
	}

	if (k == 0) {
		cout << 0 << '\n';
		return;
	}

	for (int i = n; i >= k; i--) {
		int num_to_subtract = coefs_divided[i];
		coefs_divided[i] -= num_to_subtract;
		coefs_divided[i - k] -= num_to_subtract;
	}

	int iter_num = min(n + 1, k);
	for (int i = 0; i < iter_num; i++) {
		cout << coefs_divided[i] << " ";
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n >> k;
		if (n == -1) break;
		solution();
	}
}