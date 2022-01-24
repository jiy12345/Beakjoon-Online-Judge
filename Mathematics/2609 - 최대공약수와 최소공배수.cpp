#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수 제한 사항
주어지는 자연수: 1~10,000

- 문제 상황
주어진 두 수의 최대 공약수와 최소 공배수를 구하라

2. 풀이 계획
 유클리드 호제법으로 최대 공약수를 구한 뒤, 두 수를 곱한 수를 최대공약수로 나누오 최소 공배수를 구한다!

3. 계획 검증

*/

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;	// 나머지를 구해준다.

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
