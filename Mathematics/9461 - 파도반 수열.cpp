#include<vector>
#include<iostream>
using namespace std;

void solution(int T) {
	vector<long long> P = { 1, 1, 1, 2, 2, 3, 4 };

	for (int i = 7; i < 100; i++) {
		P.push_back(P[i - 1] + P[i - 5]);
		P[i];
	}

	int N;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << P[N - 1] << endl;
	}
}

int main() {
	int T;

	cin >> T;

	solution(T);

	return 0;
}