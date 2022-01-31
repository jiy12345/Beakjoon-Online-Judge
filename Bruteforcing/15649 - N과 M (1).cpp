#include<iostream>
#include<vector>
using namespace std;

int M, N;
int sequence[8];
bool isPicked[8];
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

	for (int i = 0; i < N; i++) {
		if (isPicked[i] == false) {
			subSequence.push_back(sequence[i]);
			isPicked[i] = true;
			solution();
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
		sequence[i] = i + 1;
	}

	solution();
}
