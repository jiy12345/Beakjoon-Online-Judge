#include<iostream>
using namespace std;

int A, B, N;

int solution() {
	int answer = -1;

	int cnt = 0;
	while (true) {
		if (cnt == N) {
			answer = A / B;
			break;
		}
		A = (A % B) * 10;
		cnt++;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> N;

	cout << solution();

	return 0;
}