#include<iostream>
#include<algorithm>
#include<numeric>
#include<string>
using namespace std;

int T, n;
int candidates[10];

void solution() {
	string answer = "";

	int maxNum = *max_element(candidates, candidates + n);
	int sum = accumulate(candidates, candidates + n, 0);

	int maxNumCnt = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++) {
		if (candidates[i] == maxNum) {
			maxNumCnt++;

			if (maxNumCnt >= 2) {
				cout << "no winner\n";
				return;
			}

			maxIndex = i;
		}
	}

	if (sum < maxNum * 2)
		answer += "majority winner ";
	else
		answer += "minority winner ";

	maxIndex++;

	answer += to_string(maxIndex);

	cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> candidates[j];
		}

		solution();
	}

	return 0;
}