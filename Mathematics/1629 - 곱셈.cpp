#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
A: ������ ��
B: ������ Ƚ��
C: ���� ��

- ���� ���� ����
A, B, C: 1~2,147,483,647

- ���� ��Ȳ
 A�� B�� ���� ���� C�� ���� �������� ����Ѵ�.

2. Ǯ�� ��ȹ
 �� ���� �̹� int������ ��Ÿ�� �� �ִ� �ִ밪�� �� �� �����Ƿ�, ����

�� �˰����� ������ ����.

1. arr[k] < arr[k+1]�� �����ϴ� ���� ū k�� ���Ѵ�.
2. k ���� ��ġ���� arr[k] < arr[
4. k ���� ��ġ����, arr[k+1] ~ arr[end]�� ������ �����´�(�¿����)


3. ��ȹ ����

*/

long long solution(long long A, long long B, long long C) {

	long long answer = 1;

	A %= C;

    while (B > 0) {
        // ������ Ȧ���� ��
		// �ѷ� ��Ȯ�� �������� �����Ƿ� �ڱ� �ڽ� �ϳ� �����ֱ�
        if (B % 2 == 1) {
            answer *= A;
			answer %= C;
        }
		A = ((A % C) * (A % C)) % C;
		// B ���������� �̵� ����
		B >>= 1;
    }

	return answer;
}

int main() {
	long long A, B, C;

	cin >> A >> B >> C;

	cout << solution(A, B, C);

	return 0;
}