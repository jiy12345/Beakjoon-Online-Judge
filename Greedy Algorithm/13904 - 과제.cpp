#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001

int N, d, w, last_day;
bool visited[MAX];
vector<pair<int, int>> assignments;

int solution() {
    int answer = 0;

    sort(assignments.begin(), assignments.end(), greater<pair<int, int>>());

    for (int day = last_day; day >= 1; day--) {
        for (int i = 0; i < N; i++) {
            if (!visited[i] && assignments[i].second >= day) {
                answer += assignments[i].first;
                visited[i] = true;
                break;
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    last_day = 0;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        assignments.push_back({ w, d });
        last_day = max(last_day, d);
    }

    cout << solution();

    return 0;
}