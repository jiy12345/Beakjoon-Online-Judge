#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
n: 골드바흐 추측의 대상이 될 짝수 정수

- 변수 제한 사항
n: 6~1,000,000
테스트 케이스의 개수: 1~100,000

- 문제 상황
주어진 두 수의 최대 공약수와 최소 공배수를 구하라

2. 풀이 계획
 에라토스테네스의 체로 소수를 구한 후, 

3. 계획 검증

*/

bool isPrime[1000001];

void ertosthenesSieve(int N) {

    fill_n(isPrime, N, true);

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i])
            // i*k(k < i)에 대해서는 이전 반복에서 먼저 검사되었으므로 시작값을 i*i로 설정
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
