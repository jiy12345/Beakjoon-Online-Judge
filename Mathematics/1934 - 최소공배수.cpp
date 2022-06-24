#include<iostream>
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

void solution(int T) {
    int A, B;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        cout << lcm(A, B, gcd(A, B)) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    
    cin >> T;
    solution(T);

    return 0;
}
