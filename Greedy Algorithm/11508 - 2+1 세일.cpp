#include<iostream>
#include<algorithm>
using namespace std;

int N;
int C[100000];

int solution() {
	sort(C, C + N, greater<>());

	int sum = 0;
	for (int i = 0;i < N;i++) {
		if (i % 3 == 2) {
			continue;
		}

		sum += C[i];
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> C[i];
	}

	cout << solution();
}