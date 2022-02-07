#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


/*
1. ���� �м�
- ����
N: 1���� N������ ���� �̷���� ������ ���ϱ� ���� ����

- ���� ���� ����
N: 1~10,000

- ���� ��Ȳ
 �Է����� �־��� ������ ���� ������ ����Ѵ�.

2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

int N;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void prev_permutation(vector<int> curPermutation) {
	int length = curPermutation.size();
	int firstIndex = -1;
	int secondIndex = - 1;

	// 1. arr[k] > arr[k + 1]�� �����ϴ� ���� ū k�� ���Ѵ�.
	for (int k = length - 2; k >= 0; --k) {
		if (curPermutation[k] > curPermutation[k + 1]) {
			firstIndex = k;
			break;
		}
	}

	// i�� ã�� ���ϸ� ���� ������ ������ �����̴�.
	if (firstIndex == -1) {
		cout << -1;
		return;
	}

	// 2. i >= 1�� i�� arr[k] < arr[i]�� �����ϴ� ���� ū i ���Ѵ�.
	for (int i = length - 1; i >= 1; --i) {
		if (curPermutation[i] < curPermutation[firstIndex]) {
			secondIndex = i;
			break;
		}
	}

	// 3. arr[k]�� arr[i]�� �ٲ۴�.
	swap(curPermutation[firstIndex], curPermutation[secondIndex]);

	// 4. k ���� ��ġ����, �� arr[k + 1] ~ arr[end]�� ������ �����´�(�¿����)
	int left = firstIndex + 1;
	int right = length - 1;

	while (left < right) {
		swap(curPermutation[left], curPermutation[right]);
		left++;
		right--;
	}

	// ��� ó���� ���� ���� ���
	for (int i = 0; i < length; i++) {
		cout << curPermutation[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// ���� �Է¹ޱ�
	vector<int> curPermutation;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		curPermutation.push_back(temp);
	}

	prev_permutation(curPermutation);
}