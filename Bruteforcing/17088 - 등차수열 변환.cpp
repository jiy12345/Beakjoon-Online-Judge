#include<iostream>
using namespace std;

#define MAX 1000000000

int N, B[100000], ans = MAX;

void dfs(int prevValue, int idx, int cnt, int r) {
	if (cnt >= ans) return;
	if (idx >= N) {
		ans = min(cnt, ans);
		return;
	}
	if (B[idx] - prevValue == r) dfs(B[idx], idx + 1, cnt, r);
	if (B[idx] - 1 - prevValue == r) dfs(B[idx] - 1, idx + 1, cnt + 1, r);
	if (B[idx] + 1 - prevValue == r) dfs(B[idx] + 1, idx + 1, cnt + 1, r);
}

int solution() {
	// 가능한 시작 숫자와 동차에 따라 반복
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			dfs(B[1] + i, 2, (i != 0) + (j != 0), (B[1] + i) - (B[0] + j));
	
	return (ans != MAX) ? ans : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> B[i];

	cout << solution();
}
