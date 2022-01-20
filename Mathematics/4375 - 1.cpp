#include<iostream>
using namespace std;

int solution(int n) {
    int cnt = 1;
    int ones = 1;

    while (true) {
        ones %= n;
        if (ones == 0) {
            break;
        }

        // 자리수 세기
        cnt++;

        // 1한개 추가
        ones *= 10;
        ones++;

    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n) {
        cout << solution(n) << '\n';
    }

    return 0;
}
