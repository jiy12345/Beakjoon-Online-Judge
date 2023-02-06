#include<iostream>
using namespace std;

int t;
long long koong_array[68];

void solution() {
	koong_array[0] = 1;
	koong_array[1] = 1;
	koong_array[2] = 2;
	koong_array[3] = 4;

	for (int i = 4;i < 68;i++) {
		koong_array[i] = koong_array[i - 1] + koong_array[i - 2] + koong_array[i - 3] + koong_array[i - 4];
	}

	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;
		cout << koong_array[n] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	solution();
}