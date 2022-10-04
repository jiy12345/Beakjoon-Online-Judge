#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        int r = a % b;

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
    
    int T;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b;
        long long gcd_num = 0, lcm_num = 0;

        cin >> a >> b;

        gcd_num = gcd(a, b);
        lcm_num = lcm(a, b, gcd_num);

        cout << lcm_num << '\n';
    }

    return 0;
}