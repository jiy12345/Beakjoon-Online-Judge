#include<iostream>
using namespace std;

int A_dom, A_num;
int B_dom, B_num;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;

        a = b;
        b = r;
    }
    return a;
}

void solution() {
    int numerator = (A_num * B_dom + B_num * A_dom);
    int denominator = B_dom * A_dom;

    int gcd_of_p = gcd(numerator, denominator);

    numerator = int(numerator / gcd_of_p);
    denominator = int(denominator / gcd_of_p);

    cout << numerator << " " << denominator;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> A_num >> A_dom;
    cin >> B_num >> B_dom;

    solution();
}