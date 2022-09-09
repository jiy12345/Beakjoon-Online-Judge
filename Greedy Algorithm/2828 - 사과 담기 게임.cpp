#include<iostream>
using namespace std;

int N, M;
int J;

int solution() {
	int answer = 0;
	int left_end = 1;

	for (int i = 0; i < J; i++) {
		int curLoc;
		cin >> curLoc;
		if (curLoc < left_end) {
			answer += left_end - curLoc;
			left_end = curLoc;
		}
		else if (left_end + M - 1 < curLoc) {
			int movement = curLoc - (left_end + M - 1);
			answer += movement;
			left_end += movement;
		}
	}

	return answer;
}

int main() {
	cin >> N >> M;
	cin >> J;

	cout << solution();
}