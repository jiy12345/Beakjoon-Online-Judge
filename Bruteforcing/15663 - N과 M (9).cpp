#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int M, N;
int sequence[8];
bool isPicked[8];
vector<int>subSequence;

void permutation() {
	int curSize = subSequence.size();
	if (curSize == M) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	int isUsed = 0;
	for (int i = 0; i < N; i++) {
		if (isPicked[i] == false &&sequence[i] != isUsed) {
			subSequence.push_back(sequence[i]);
			isUsed = sequence[i];
			isPicked[i] = true;
			permutation();
			subSequence.pop_back();
			isPicked[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}

	sort(sequence, sequence + N);

	permutation();
}
