#include<iostream>
#include<limits.h>
using namespace std;

int N;

int solution() {
	int minNum = INT_MAX;
	int maxNum = 0;

	for (int i = 0;i < N; i++) {
		int curNum;
		cin >> curNum;

		minNum = min(minNum, curNum);
		maxNum = max(maxNum, curNum);
	}

	return (maxNum - minNum) * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution();

	return 0;
}