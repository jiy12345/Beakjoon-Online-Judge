#include<iostream>
using namespace std;

bool is_erased[1001];
int N, K;

int solution() {
	int cnt = 0;
	for (int i = 2;i <= N;i++) {
  		for (int j = i;j <= N;j += i) {
			if (is_erased[j] == false) {
				is_erased[j] = true;
				cnt++;
			}
			if (cnt == K) {
				return j;
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	cout << solution();
}