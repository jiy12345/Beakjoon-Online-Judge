#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
N: �־����� �ڿ���

- ���� ���� ����
N: 1~1,000,000

- ���� ��Ȳ

f(A): �ڿ��� A�� ����� ��

g(x): x���� �۰ų� ���� ��� �ڿ��� y�� f(y)�� ���� ��

2. Ǯ�� ��ȹ

��� ���� ����� ���ؾ� �ϴµ� ��...

3. ��ȹ ����

*/

int N;

long long solution() {
    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        answer += (N / i) * i;
    }

    return answer;
}

int main() {

    cin >> N;

    cout << solution();

    return 0;
}
