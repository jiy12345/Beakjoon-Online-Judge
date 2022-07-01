#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int M, N;
int sequence[8];
bool UsedIndex[8];
vector<int>subSequence;

void solution() {
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
		if (isUsed == sequence[i]) continue;
		isUsed = sequence[i];
		UsedIndex[i] = true;

		subSequence.push_back(sequence[i]);
		solution();
		subSequence.pop_back();
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

	solution();
}