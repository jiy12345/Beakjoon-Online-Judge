#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int mathGrades[50];

void solution(int index) {
	sort(mathGrades, mathGrades + N, greater<>());

	int largestGap = 0;
	for (int i = 0; i < N - 1; i++) {
		largestGap = max(largestGap, mathGrades[i] - mathGrades[i + 1]);
	}

	cout << "Class " << index + 1 << '\n';
	cout << "Max " << mathGrades[0] << ", ";
	cout << "Min " << mathGrades[N - 1] << ", ";
	cout << "Largest gap " << largestGap << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> mathGrades[j];
		}

		solution(i);
	}
}