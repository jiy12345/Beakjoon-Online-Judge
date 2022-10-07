#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> times;

int solution() {
    int days = 0;

    for (int i = 0; i < N; i++)
        days = max(days, times[i] + i + 1);

    return days + 1
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        times.push_back(x);
    }

    sort(times.rbegin(), times.rend());

    cout << solution();
}