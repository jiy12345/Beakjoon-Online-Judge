#include<iostream>
using namespace std;

long long N;
int L;

void solution() {
	int res = -1, index = 0;
	// 가능한 모든 길이에 대해 고려
	for (int i = L; i <= 100; i++) {
		int k = i * (i - 1) / 2;
		// 시작 숫자 구하기
		int start_num = (N - k) / i;
		if ((N - k) % i == 0 && start_num >= 0) {
			res = start_num;
			index = i;
			break;
		}
	}

	if (res == -1) cout << -1;
	else for (int i = 0; i < index; i++) cout << res + i << " ";
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> L;

	solution();
}
