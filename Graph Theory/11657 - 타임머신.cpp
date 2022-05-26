#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 501
#define INF 999999999

int N, M;
long long node[MAX];
vector<pair<pair<int, int>, int>> edge;

bool bellman_ford() {
    // 벨만 포드 알고리즘
    node[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int cur_node, next_node, dist;
            cur_node = edge[j].first.first;
            next_node = edge[j].first.second;
            dist = edge[j].second;

            if (node[cur_node] == INF)
                continue;

            if (node[next_node] > node[cur_node] + dist) {
                node[next_node] = node[cur_node] + dist;

                if (i == N)
                    return false;
            }
        }
    }

    return true;
}

void solution() {
    if (!bellman_ford()) {
        cout << -1;
        return;
    }

    // 출력
    for (int i = 2; i <= N; i++) {
        if (node[i] == INF)
            cout << -1 << '\n';
        else
            cout << node[i] << '\n';
    }
}

int main() {
    cin>> N >> M;

    fill(&node[0], &node[MAX], INF);

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edge.push_back({ { A, B }, C });
    }

    solution();
}