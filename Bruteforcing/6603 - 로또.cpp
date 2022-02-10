#include<iostream>
#include<vector>
using namespace std;

int sequence[13];
vector<int>subSequence;

void solution(int index, int k) {
	int curSize = subSequence.size();
	if (curSize == 6) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = index; i < k; i++) {
		subSequence.push_back(sequence[i]);
		solution(i + 1, k);
		subSequence.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;

	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> sequence[i];
		}
		solution(0, k);
		cout << "\n";

		cin >> k;
	}

	return 0;
}
