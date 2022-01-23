#include<iostream>
#include<algorithm>
using namespace std;

int N, T;
int X[100000];
long long FY[1000001];
long long FX[1000001];

void solution(int N) {

    fill_n(FX, N + 1, 1);

    for (int i = 2; i <= N; i++) {
        for (int j = 1; i * j <= N; j++) {
            FX[i * j] += i;
        }
    }
    for (int i = 1; i <= N; i++) {
        FY[i] = FY[i - 1] + FX[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> X[i];
    }

    int max_num = *max_element(X, X + T);

    solution(max_num);

    for (int i = 0; i < T; i++) {
        cout << FY[X[i]] << '\n';
    }

    return 0;
}
