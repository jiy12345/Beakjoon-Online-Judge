#include<iostream>
using namespace std;

int preOrderedTree[10005];

void postOrder(int start, int end) {
	if (start >= end) return;

	int i = start + 1;
	for (i; i < end; i++)
		if (preOrderedTree[start] < preOrderedTree[i]) break;

	postOrder(start + 1, i);
	postOrder(i, end);
	cout << preOrderedTree[start] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0, x;

	while (cin >> preOrderedTree[n++]);

	postOrder(0, n - 1);

	return 0;
}
