#include<iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;

        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b, long long gcd) {
    return a * b / gcd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    cout << lcm(A, B, gcd(A, B)) << '\n';

    return 0;
}