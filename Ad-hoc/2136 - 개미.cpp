#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 100001

int N, L;
int v[MAX];

pair<int, int> res[MAX];

void solution() {
    int left_cnt = 0, max_dist_left = 0, max_dist_right = 0;

    for (int i = 1; i <= N; i++) {
        if (v[i] >= 0) {
            max_dist_right = max(L - v[i], max_dist_right);
        }
        else {
            left_cnt++;
            max_dist_left = max(abs(v[i]), max_dist_left);
        }

        res[i - 1] = make_pair(abs(v[i]), i);
    }

    sort(res, res + N);

    if (max_dist_left > max_dist_right) {
        cout << res[left_cnt - 1].second << " " << max_dist_left;
    }
    else {
        cout << res[left_cnt].second << " " << max_dist_right;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    solution();

    return 0;
}