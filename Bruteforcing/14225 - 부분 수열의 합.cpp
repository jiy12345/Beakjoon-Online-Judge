#include<iostream>
#include<string>
using namespace std;

int S[21];
bool canMake[2000001];
int sum, N;

void combination(int x, int sum) {
	canMake[sum] = true;
	if (x == N) return;
	else {
		combination(x + 1, sum);
		combination(x + 1, sum + S[x]);
	}
}

int solution() {
	combination(0, 0);

	int cnt = 1;
	while(canMake[cnt] == true) cnt++;

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	cout << solution();
}
