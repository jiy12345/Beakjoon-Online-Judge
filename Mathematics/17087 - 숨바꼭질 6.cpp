#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N, S;
vector<int> A;

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

int solution() {
    int answer = A[0];
    for (int i = 1; i < N; i++) {
        answer = gcd(answer, A[i]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(abs(a - S));
    }

    cout << solution();

    return 0;
}