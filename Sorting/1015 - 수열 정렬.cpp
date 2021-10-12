#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: �迭�� ũ��

- ���� ���� ����
N: 1~50
�迭�� ����: 1~1,000

- ���� ��Ȳ
 ���� P�� �迭 A�� ������ �迭 B��

 B[P[i]] = A[i]

 �񳻸�����: �ٷ� ���� ���ҿ� ���� ���� �ִ� ��������

 �迭 A�� �־����� ��, ���� P�� ������ ����� �񳻸��������� ���ĵǵ����ϴ� ���� P�� ���϶�



2. Ǯ�� ��ȹ

���� �ڼ��� ��ȹ�� ������ ����.

1. �迭�� �Է¹��� �� �����Ѵ�. ��Ī�� �迭�� Ȱ���ϱ� ���� ���� �迭�� ���´� �����Ѵ�.
2. ������ ������ �����ϰ�, ������ ������ �� �ε����� ��Ī�Ͽ� ������ �����.
3. ���� �� Ű�� ���� �Էµ� �迭�� ������� ����ִ´�.



3. ��ȹ ����

*/

int N;

void solution() {
	map<int, int> array_map;
	vector<int> A;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}

	vector<int> unordered_A = A;

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		array_map[A[i]] = i;
	}


	for (int i : unordered_A) {
		cout << array_map[i] << " ";
	}

}

int main() {
	cin >> N;

	solution();
}