#include<iostream>
using namespace std;

int w, h, p, q, t;

void solution() {
    int answer = 0;
    p += t; q += t;
    p %= (2 * w); q %= (2 * h);
    if (p > w) p = 2 * w - p;
    if (q > h) q = 2 * h - q;

    cout << p << " " << q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    solution();
}
