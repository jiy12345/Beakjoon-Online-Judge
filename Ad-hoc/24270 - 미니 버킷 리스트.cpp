#include <iostream>
#include <vector>

using namespace std;

int N, K;

long long factorial(int r) {
    long long result = 1;
    for (int i = 1; i <= N; i++) {
        result = result * (r + i) % 1000000007;
    }

    return result;
}

long long solution(int sum) {
    int r = K - sum;

    return factorial(r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
    }

    cout << solution(sum);
}
