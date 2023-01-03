#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int A[100000];

bool binary_search(int cur_num) {
	int left = 0;
	int right = N - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (A[mid] == cur_num) return true;
		else if (cur_num < A[mid]) right = mid - 1;
		else left = mid + 1;
	}

	return false;
}

void solution() {
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int cur_num;
		cin >> cur_num;
		cout << (binary_search(cur_num) ? 1 : 0) << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	solution();
}
