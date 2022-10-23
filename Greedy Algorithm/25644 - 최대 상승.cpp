#include<iostream>
#include<limits.h>
using namespace std;

int N;

int solution() {
	int answer = 0;
	
	int minPrice = INT_MAX;
	for (int i = 0; i < N; i++) {
		int curPrice;
		cin >> curPrice;

		answer = max(answer, curPrice - minPrice);

		minPrice = min(minPrice, curPrice);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solution();

	return 0;
}