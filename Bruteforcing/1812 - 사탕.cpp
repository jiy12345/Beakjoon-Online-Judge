#include<iostream>
using namespace std;

int N;
int number_of_candies[1000];

void solution() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> number_of_candies[i];
		sum += number_of_candies[i];
	}
	sum /= 2;

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 0; j < N; j += 2)
			tmp += number_of_candies[(i + j) % N];
		cout << tmp - sum << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	solution();
}