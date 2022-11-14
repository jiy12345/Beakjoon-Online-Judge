#include<iostream>
#include<cstring>
using namespace std;

bool isAppeared[10];
int N, M;

int solution() {
	int answer = M - N + 1;

	for (int i = N; i <= M; i++) {
		memset(isAppeared, false, sizeof(isAppeared));
		int curNum = i;
		while (true) {
			int curDigit = curNum % 10;
			if (isAppeared[curDigit]) {
				answer--;
				break;
			}
			isAppeared[curDigit] = true;
			curNum /= 10;
			if (curNum == 0) break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> N >> M) {
		cout << solution() << '\n';
	}
}