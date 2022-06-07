#include<iostream>
using namespace std;

int t;
int n, l;

void solution() {
    int maxTime = 0;
    int minTime = 0;

    int location;
    for (int i = 0; i < n; i++) {
        cin >> location;

        minTime = max(minTime, min(location, l - location));
        maxTime = max(maxTime, max(location, l - location));
    }

    cout << minTime << " " << maxTime << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> l >> n;
        solution();
    }
}
