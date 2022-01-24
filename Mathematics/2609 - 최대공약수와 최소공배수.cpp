#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;

        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int gcd) {
    return a * b / gcd;
}

int main() {
    int a, b;
    int gcd_num = 0, lcm_num = 0;

    cin >> a >> b;

    gcd_num = gcd(a, b);
    lcm_num = lcm(a, b, gcd_num);

    cout << gcd_num << '\n';
    cout << lcm_num;

    return 0;
}
