#include <iostream>
using namespace std;
#define MAX 1000000

int primeNumbers[MAX + 1]{ 0, };

void eratos() {
    for (int i = 2; i <= MAX; i++) {
        primeNumbers[i] = i;
    }

    for (int i = 2; i * i <= MAX; i++) {
        if (primeNumbers[i] == 0) {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i) {
            primeNumbers[j] = 0;
        }
    }
}

int solution(int n) {
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (primeNumbers[n - i] + primeNumbers[i] == n) {
            cnt++;
            if (n - i == i)
            {
                cnt++;
            }
        }
    }

    return cnt / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    eratos();

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << solution(n) << '\n';
    }

    return 0;
}