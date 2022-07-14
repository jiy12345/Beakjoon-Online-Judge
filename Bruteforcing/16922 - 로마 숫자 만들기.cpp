#include<iostream>
using namespace std;

int N;

int romanNum[4] = { 1, 5, 10, 50 };
bool isVisited[20 * 50 + 1];

int perm_comb(int curIndex, int curPicked, int curSum) {
	int answer = 0;
	if (curPicked == N) {
		if (isVisited[curSum] == false) {
			isVisited[curSum] = true;
			return 1;
		}
		return 0;
	}

	for (int i = curIndex; i < 4; i++) {
		answer += perm_comb(i, curPicked + 1, curSum + romanNum[i]);;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << perm_comb(0, 0, 0);
}
