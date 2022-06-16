#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

pair<int, char> ant[70001];
int L, T, N;

void getPosition() {
    for (int i = 0; i < N; i++) {
        int p, q;
        int t;

        if (ant[i].second == 'L') {
            t = T - ant[i].first;
            if (t < 0)
                ant[i].first -= T;
            else {
                p = t / L;
                q = t % L;
                ant[i].first = p & 1 ? L - q : q;
            }
        }
        else {
            t = T - (L - ant[i].first);
            if (t < 0)
                ant[i].first += T;
            else {
                p = t / L;
                q = t % L;
                ant[i].first = p & 1 ? q : L - q;
            }
        }
    }

    sort(ant, ant + N);
}

void solution() {
    getPosition();

    for (int i = 0; i < N; i++)
        cout << ant[i].first << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> L >> T;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> ant[i].first >> ant[i].second;

    solution();

    return 0;

}
