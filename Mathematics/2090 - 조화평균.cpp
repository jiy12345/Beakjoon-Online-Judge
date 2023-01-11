#include<iostream>
using namespace std;

int N;
int A[10];

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;

        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void solution() {
    long long numerator = 1;
    long long denominator = A[0];
    for (int i = 1; i < N; i++) {
        long long lcm_num = lcm(denominator, A[i]);

        long long rhs_numerator = numerator * (lcm_num / denominator);
        long long lhs_numerator = 1 * (lcm_num / A[i]);
        denominator = lcm_num;

        numerator = rhs_numerator + lhs_numerator;
    }

    long long gcd_num = gcd(numerator, denominator);

    cout << denominator / gcd_num << '/' << numerator / gcd_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solution();
}