#include<iostream>
#include<vector>
using namespace std;

/*
1. ���� �м�
- ����
n: ������ ������ ����� �� ¦�� ����

- ���� ���� ����
n: 6~1,000,000
�׽�Ʈ ���̽��� ����: 1~100,000

- ���� ��Ȳ
�־��� �� ���� �ִ� ������� �ּ� ������� ���϶�

2. Ǯ�� ��ȹ
 �����佺�׳׽��� ü�� �Ҽ��� ���� ��, 

3. ��ȹ ����

*/

bool isPrime[1000001];

void ertosthenesSieve(int N) {

    fill_n(isPrime, N, true);

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i])
            // i*k(k < i)�� ���ؼ��� ���� �ݺ����� ���� �˻�Ǿ����Ƿ� ���۰��� i*i�� ����
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
    }
}

void GoldbachsConjecture(int n) {
    int a = 0;
    int b = 0;

    int i;

    for (i = 3; i <= n / 2; i += 2) {
        if (isPrime[i] && isPrime[n - i]) {
            a = i;
            b = n - i;
            break;
        }
    }

    if (i == n / 2 + 1) {
        cout << "Goldbach's conjecture is wrong." << '\n';
    }
    else {
        cout << n << " = " << a << " + " << b << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ertosthenesSieve(1000000);

    int n;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        GoldbachsConjecture(n);
    }

    return 0;
}
