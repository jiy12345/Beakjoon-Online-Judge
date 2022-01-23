#include<iostream>
#include<vector>
using namespace std;

int N, T;
long long FY[1000001];

void solution() {
    vector<long long> FX(1000001, 1);
    for (int i = 2; i <= 1000000; i++) {
        for (int j = 1; i * j <= 1000000; j++) {
            FX[i * j] += i;
        }
    }
    for (int i = 1; i <= 1000000; i++) {
        FY[i] = FY[i - 1] + FX[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    solution();

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << FY[N] << '\n';
    }

    return 0;
}
