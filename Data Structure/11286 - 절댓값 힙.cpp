#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

/*
1. ���� �м�

- ����
N: �־��� ������ ����

- ���� ���� ����
4 <= N <= 100,000
0 <= �ԷµǴ¼� <= 2^31

 - ���� ��Ȳ
 �ԷµǴ� ���� �ڿ������ �迭�� �ڿ����� �Է��ϰ�, �ڿ����� �ƴ� 0�̶�� �迭���� ���� ū ���� ����ϰ� �� ���� �迭���� �����ϴ� ������ �ϵ��� ���α׷��� �ۼ��϶�.
 �� �� �迭�� ����ִµ� ����� �䱸�� ��� 0�� ����Ѵ�.

2. Ǯ�� ��ȹ
 �� ������ c++���� �����ϴ� <queue>���̺귯��(�켱���� ť�� ������ ���̺귯��)�� ����ϸ� ����� �ʰ� Ǯ �� ���� �� �ϴ�.

 �켱���� ť�� ���ǿ� ���� ��� ���ҿ� ���� �񱳿����� �ִ� ��(���� ��� �ִ밪, �ּҰ� ��)�� top�� ��ġ����, �ش� ���� O(1)�� �ð����⵵�� Ž���� �����ϰ� �ϴ� �ڷᱸ���̴�.

 ���� �ڼ��� ������ ������ ����.

1. top�� �׻� �ִ밪�� �켱���� ť�� �����Ѵ�.
2. �Է¿� ���� ���� �ൿ�� �����Ѵ�.
 1) 0�� �ԷµǸ� top�� �ִ� ���� ����ϰ� top�� �ִ� ���� �����Ѵ�.
 2) �ڿ����� �ԷµǸ� �ڿ����� �켱���� ť�� �����Ѵ�.

3. ��ȹ ����


*/

int N;

class comp {
public: 
	bool operator()(const int& lhs, const int& rhs) const {
		// �� ���� ���밪�� ���ٸ�
		if (abs(lhs) == abs(rhs)) {
			// �� ��ȣ�� ���� ���� ����
			return lhs > rhs;
		}
		else { // ���밪�� �ٸ��ٸ�, ���밪�� �������� ����
			return abs(lhs) > abs(rhs);
		}

	}
};

void solution() {
	priority_queue<int, vector<int>, comp> abs_min_heap;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0) {
			if (abs_min_heap.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << abs_min_heap.top() << '\n';
				abs_min_heap.pop();
			}
		}
		else {
			abs_min_heap.push(input);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();
}