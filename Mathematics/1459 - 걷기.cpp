#include<iostream>
using namespace std;

int X, Y, W, S;

long long solution() {
	long long answer = 0;

	long long min_num = min(X, Y);
	long long max_num = max(X, Y);

	answer = (max_num + min_num) * W;
	if ((X + Y) % 2 == 0) {
		answer = min(answer, max_num * S);
	}
	else {
		answer = min(answer, (max_num - 1) * S + W);
	}
	answer = min(answer, (max_num - min_num) * W + min_num * S);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X >> Y >> W >> S;
	cout << solution();
}