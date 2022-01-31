#include<iostream>
#include<vector>
using namespace std;

int M, N;
int sequence[8];
vector<int>subSequence;

void solution(int index) {
	int curSize = subSequence.size();
	if (curSize == M) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = index; i < N; i++) {
		subSequence.push_back(sequence[i]);
		solution(i + 1);
		subSequence.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		sequence[i] = i + 1;
	}

	solution(0);
}
