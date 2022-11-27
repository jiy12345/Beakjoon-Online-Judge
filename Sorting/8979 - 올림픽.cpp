#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
vector<vector<int>> numOfMedals;

bool comp(const vector<int>& lhs, const vector<int>& rhs) {
	if (lhs[0] == rhs[0]) {
		if (lhs[1] == rhs[1]) {
			if (lhs[2] == rhs[2]) {
				return lhs[3] < rhs[3];
			}
			return lhs[2] > rhs[2];
		}
		return lhs[1] > rhs[1];
	}
	return lhs[0] > rhs[0];
}

int solution() {
	sort(numOfMedals.begin(), numOfMedals.end(), comp);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (numOfMedals[i][3] == K) {
			answer = i + 1;
			int index = i - 1;
			while (true) {
				if (index < 0 ||
					(numOfMedals[i][0] != numOfMedals[index][0] ||
					numOfMedals[i][1] != numOfMedals[index][1] ||
					numOfMedals[i][2] != numOfMedals[index][2]))
						break;
				answer--;
				index--;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	numOfMedals.resize(N);
	for (int i = 0; i < N; i++) {
		numOfMedals[i].resize(4);
		cin >> numOfMedals[i][3] >> numOfMedals[i][0] >> numOfMedals[i][1] >> numOfMedals[i][2];
	}

	cout << solution();
}