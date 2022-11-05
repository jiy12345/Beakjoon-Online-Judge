#include<iostream>
#include<vector>
using namespace std;

int N;
vector<float> input;

void solution() {
	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < 7; i++) {
		float min = 100.0f;
		int minIndex = 0;
		for (int j = 0; j < N - i; j++) {
			if (min >= input[j]) {
				min = input[j];
				minIndex = j;
			}
		}
		cout << min << '\n';
		input.erase(input.begin() + minIndex);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	input.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	solution();
}