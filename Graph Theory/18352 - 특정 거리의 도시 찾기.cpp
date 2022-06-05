#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 300001

int dist[300001];
vector<vector<int>> way;

int N, M, K, X;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    dist[X] = 0;
    pq.push(make_pair(0, X));

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_cost)
            continue;

        for (int i = 0; i < way[cur_node].size(); i++) {
            int next_cost = cur_cost + 1;
            int next_node = way[cur_node][i];

            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push(make_pair(next_cost, next_node));

            }

        }
    }
}

void solution() {
    fill(&dist[0], &dist[N], N);

    dijkstra();

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << '\n';
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K >> X;
    way.resize(N + 1);

    int start, end;
    for (int i = 0; i < M; i++) {
        cin >> start >> end;
        way[start].push_back(end);
    }

    solution();
}