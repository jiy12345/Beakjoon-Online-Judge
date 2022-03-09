#include<iostream>
using namespace std;


/*
1. ���� �м�
- ����
N: ������ ���� ����
S: ��ǥ�� �ϴ� ��

- ���� ���� ����
N: 1 ~ 10,000
M: 1 ~ 100,000,000
������ ���Ե� ��: 1 ~ 10,000

- ���� ��Ȳ
 i��° ������ j��° �������� �� A[i] + A[i+1] + �� + A[j-1] + A[j]�� M�� �Ǵ� ����� ���� ���Ͽ���

2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

int A[100001];
int N, S;

int solution() {
	int answer = N + 1;

	int sum = A[0];
	int i = 0;
	int j = 0;

	while (true) {
		if (sum >= S) {
			// �ϳ��� ���� S �̻��� ���
			if (i == j)  return 1;
			answer = min(answer, j - i + 1);
			sum -= A[i++];
		}
		else {
			sum += A[++j];
		}

		if (i >= N || j >= N) break;
	}

	if (answer == N + 1) answer = 0;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution();
}