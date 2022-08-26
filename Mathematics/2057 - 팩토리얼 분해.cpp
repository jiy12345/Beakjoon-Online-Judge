#include<iostream>
#include<vector>
using namespace std;

long long N;
vector<long long>factorials;

bool binCoef(long long curSum, int curIndex, int maxIndex) {
	if (curIndex == maxIndex) {
		if (curSum == N) return true;
		else			 return false;
	}

	for (int i = 0; i < 2; iS++) {
		if (binCoef(curSum + factorials[curIndex] * i, curIndex + 1, maxIndex) == true)
			return true;
	}

	return false;
}

string solution() {
	if (N == 0) return "NO";
	int maxIndex = 0;
	long long curFactorial = 1;

	while (true) {
		if (curFactorial > N) break;
		factorials.push_back(curFactorial);
		curFactorial *= ++maxIndex;
	}

	return (binCoef(0, 0, maxIndex) ? "YES" : "NO");
}

int main() {
	cin >> N;

	cout << solution();
}