#include<iostream>
#include<algorithm>
using namespace std;

int n, x;
int a[100000];

int solution() {
	sort(a, a + n);

	int left = 0;
	int right = n - 1;

	int cnt = 0;
	while (left < right) {
		int sum = a[left] + a[right];

		if (sum > x) {
			right--;
		}
		else if (sum < x) {
			left++;
		}
		else {
			cnt++;
			left++;
			right--;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cin >> x;

	cout << solution();
}