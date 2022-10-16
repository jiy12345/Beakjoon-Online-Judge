#include<iostream>
using namespace std;

int N;

void solution() {
	for (int j = 0; j < N; j++) {
		cout << "*";
	}
	for (int j = 0; j < 2 * (N - 1) - 1; j++) {
		cout << " ";
	}
	for (int j = 0; j < N; j++) {
		cout << "*";
	}

	cout << '\n';

	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < N - 2; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < 2 * (N - 1) - 1 - 2 * i; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < N - 2; j++) {
			cout << " ";
		}
		cout << "*";
		cout << '\n';
	}

	for (int j = 0; j < N - 1; j++) {
		cout << " ";
	}
	cout << "*";
	for (int j = 0; j < N - 2; j++) {
		cout << " ";
	}
	cout << "*";
	for (int j = 0; j < N - 2; j++) {
		cout << " ";
	}
	cout << "*\n";

	for (int i = N - 2; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < N - 2; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < 2 * (N - 1) - 1 - 2 * i; j++) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < N - 2; j++) {
			cout << " ";
		}
		cout << "*";
		cout << '\n';
	}

	for (int j = 0; j < N; j++) {
		cout << "*";
	}
	for (int j = 0; j < 2 * (N - 1) - 1; j++) {
		cout << " ";
	}
	for (int j = 0; j < N; j++) {
		cout << "*";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();
}