#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ �����ϴ� ���� ����

- ���� ���� ����
N: 1~10,000

- ���� ��Ȳ
 ���� �ϳ��� �־��� ��, �� ������ ��ġ�� ������ ����϶�


2. Ǯ�� ��ȹ
���� ������ 10,000���̹Ƿ�, ��ü�� �غ��� ���� 10,000! ������ ����� ���� �����Ƿ� �Ұ����� �� ���δ�.

���� ��Ģ���� ã�� ���� ������ ���� �״��� ������ ã�� �� �ִ� ����� ���ؾ� �Ѵ�!

���� ������ ��� ���ؾ��� �� �������� �ʾ� ����ߴµ�, �̹� �����ϴ� �˰����� �־���.

�� �˰����� ������ ����.

1. arr[k] < arr[k+1]�� �����ϴ� ���� ū k�� ���Ѵ�.
2. k ���� ��ġ���� arr[k] < arr[i]�� �����ϴ� ���� ū i�� ���Ѵ�.
3. arr[k]�� arr[i]�� �ٲ۴�.
4. k ���� ��ġ����, arr[k+1] ~ arr[end]�� ������ �����´�(�¿����)


3. ��ȹ ����

*/

int N;

void next_permutation() {
	// ���� �Է¹ޱ�
	vector<int> arr;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	if (N == 1) {
		cout << -1;
		return;
	}

	int k = N - 2;
	// 1. arr[k] < arr[k+1]�� �����ϴ� ���� ū k�� ���Ѵ�.
	while (arr[k] > arr[k + 1]) {
		if (k == 0) {
			// �ݴ�� ���ĵǾ� ���� ��� -1 ���
			cout << -1;
			return;
		}
		k--;
	}

	int i = N - 1;
	while (arr[k] > arr[i]) {
		i--;
		if (i == k + 1) {
			break;
		}
	}

	// 3. arr[k]�� arr[i]�� �ٲ۴�.
	temp = arr[k];
	arr[k] = arr[i];
	arr[i] = temp;

	// 4. k ���� ��ġ����, arr[k + 1] ~arr[end]�� ������ �����´�(�¿����)
	for (int i = 1; i < (int)floor((N - k - 1)/2) + 1; i++) {
		temp = arr[k + i];
		arr[k + i] = arr[N - i];
		arr[N - i] = temp;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	cin >> N;

	next_permutation();
}