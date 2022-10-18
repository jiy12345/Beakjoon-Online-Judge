#include <iostream>
using namespace std;

int N;

string solution() {
	if (N % 2 == 1) {
		return "SK";
	}

	else {
		return "CY";
	}
}

int main() {
	cin >> N;

	cout << solution();

	return 0;
}