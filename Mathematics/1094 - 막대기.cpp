#include<iostream>
using namespace std;

int X;

int solution() {
	int answer = 0;
	for (int i = 64; i > 0; i /= 2) {
		if (!X)
			break;
		if (i <= X) {
			answer++;
			X = X - i;
		}
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X;

	cout << solution();

	return 0;
}
