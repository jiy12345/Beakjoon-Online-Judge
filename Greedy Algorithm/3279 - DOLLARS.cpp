#include<iostream>
#include<iomanip>
using namespace std;

int N;

double solution() {
	double answer = 100.0f;

	int prev_A, cur_A;
	cin >> prev_A;

	for (int i = 0; i < N - 1; ++i) {
		cin >> cur_A;
		if (prev_A > cur_A)
			answer *= (float)prev_A / cur_A;
		prev_A = cur_A;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << fixed;
	cout.precision(2);
	cout << solution();
}