#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 50

int S[MAX];
int L, n;

int solution() {
	sort(&S[0], &S[L]);

	// n이 포함되는 구간 찾기
	int prevNum = 0;
	int nextNum = 0;
	for (int i = 0; i < L; i++) {
		// n S에 포함되는 경우 n이 속하는 좋은 구간이 나올 수 없음
		if (S[i] == n) return 0;
		if (S[i] > n) {
			nextNum = S[i];
			prevNum = S[i - 1];
			break;
		}
	}

	// 좋은 구간의 개수 구하기
	int answer = 0;
	for (int k = prevNum + 1; k <= n; k++) {
		answer += (nextNum - 1) - max((n - 1), k);
	}
	return answer;
}

void input() {
	cin >> L;

	for (int i = 0; i < L; i++)
		cin >> S[i];

	cin >> n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	cout << solution();
}
