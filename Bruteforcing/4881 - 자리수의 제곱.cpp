#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A, B;

inline int sumOfSquares(int X) {
	int sumOfSquares = 0;

	while (true) {
		sumOfSquares += (X % 10) * (X % 10);
		X /= 10;
		if (X == 0) break;
	}

	return sumOfSquares;
}

int solution() {
	int answer = 0;

	int curA = A;
	vector<int> sequenceOfA;
	sequenceOfA.push_back(A);
	while (true) {
		int nextA = sumOfSquares(curA);

		if (find(sequenceOfA.begin(), sequenceOfA.end(), nextA) != sequenceOfA.end()) break;
		
		sequenceOfA.push_back(nextA);
		curA = nextA;
	}

	int curB = B;
	vector<int> sequenceOfB;
	sequenceOfB.push_back(B);
	while (true) {
		int nextB = sumOfSquares(curB);

		if (find(sequenceOfB.begin(), sequenceOfB.end(), nextB) != sequenceOfB.end()) break;

		sequenceOfB.push_back(nextB);
		curB = nextB;
	}

	int sumOfLength = sequenceOfA.size() + sequenceOfB.size() + 2;
	int i;
	for (i = 0; i < sequenceOfA.size(); i++) {
		auto posOfNum = find(sequenceOfB.begin(), sequenceOfB.end(), sequenceOfA[i]);
		if (posOfNum != sequenceOfB.end()) {
			int lengthOfA = i;
			int lengthOfB = posOfNum - sequenceOfB.begin();
			sumOfLength = min(sumOfLength, lengthOfA + lengthOfB);
		}
	}

	sumOfLength += 2;
	if(sumOfLength == sequenceOfA.size() + sequenceOfB.size() + 4) sumOfLength = 0;
	
	return sumOfLength;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	while (true) {
		cin >> A >> B;

		if (A == 0 && B == 0) break;

		cout << A << " " << B << " " << solution() << '\n';
	}

	return 0;
}
