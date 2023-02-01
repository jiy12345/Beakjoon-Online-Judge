#include<iostream>
using namespace std;

int N;

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;

        a = b;
        b = r;
    }
    return a;
}

void solution() {
    int first_circle_length;
    cin >> first_circle_length;

    for (int i = 0;i < N - 1;i++) {
        int cur_circle_length;
        cin >> cur_circle_length;

        int gcd = GCD(first_circle_length, cur_circle_length);

        cout << first_circle_length / gcd << '/' << cur_circle_length / gcd << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();
}