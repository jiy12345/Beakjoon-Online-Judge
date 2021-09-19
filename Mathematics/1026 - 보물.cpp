#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ ����


- ���� ����
1 <= N <= 50
0 <= A�� ����, B�� ���� <= 100


- ���� ��Ȳ
S = A[0]��B[0] + ... + A[N-1]��B[N-1]�� ��,
S�� �ּڰ��� ����ϴ� ���α׷��� �ۼ��϶�

2. Ǯ�� ��ȹ
B�� �ִ� ���� ��迭���� ������ ������, �ּڰ����� ����ϴ� �����̹Ƿ� ��迭�ص� ������ ���� �� ����.

���� B�� ������������, A�� ������������ ������ ��, ���� �ε����� �ִ� ������ ���� �� ���ϸ� �� �� �ϴ�!

*/

int solution(int N, vector<int> A, vector<int> B) {
	long long answer = 0;

	sort(B.begin(), B.end(), greater<int>());
	sort(A.begin(), A.end());

	for (int i = 0;i < N;i++) {
		answer += A[i] * B[i];
	}

	return answer;
}

int main() {
	int N, temp;
	vector<int> A, B;

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> temp;
		A.push_back(temp);
	}	
	for (int i = 0;i < N;i++) {
		cin >> temp;
		B.push_back(temp);
	}

	cout << solution(N, A, B);

	return 0;
}