#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
투 포인터 알고리즘을 활용한 풀이


*/

int t, n, m;
int A[1000], B[1000];
vector<int> A_sum, B_sum;

long long solution() {
	long long answer = 0;

	// A 부분 배열의 합 구하기
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += A[j];
			A_sum.push_back(sum);
		}
	}

	// B 부분 배열의 합 구하기
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		for (int j = i; j < m; ++j) {
			sum += B[j];
			B_sum.push_back(sum);
		}
	}

	// 투 포인터 사용을 위해 두 배열 정렬
	sort(A_sum.begin(), A_sum.end());
	sort(B_sum.begin(), B_sum.end());

	int left = 0, right = B_sum.size() - 1;

	// 투 포인터가 범위 벗어날때까지 계속
	while (left < A_sum.size() && right >= 0) {
		int add = A_sum[left] + B_sum[right];

		if (add < t) ++left;
		else if (add == t) {
			long long a = 1, b = 1;

			while (left < A_sum.size() - 1 && A_sum[left] == A_sum[left + 1]) {
				++left, ++a;
			}
			while (right >= 1 && B_sum[right] == B_sum[right - 1]) {
				--right, ++b;
			}
			answer += a * b;
			++left;
		}
		else --right;
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> B[i];

	cout << solution() << endl;

	return 0;
}