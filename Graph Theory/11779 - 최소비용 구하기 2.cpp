#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>
using namespace std;

#define MAX 1001
#define INF 100000 * 100000

int n, m;
int start_node, end_node;

vector<pair<int, int>> graph[MAX];
long long distFromStart[MAX];
int prevNode[MAX];

void dijkstra(int startNode) {

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> dijkstra_queue;

    dijkstra_queue.push({ 0, startNode });
    distFromStart[startNode] = 0;

    while (!dijkstra_queue.empty()) {
        long long cur_cost = dijkstra_queue.top().first;
        int cur_node = dijkstra_queue.top().second;
        dijkstra_queue.pop();

        if (distFromStart[cur_node] < cur_cost) continue;

        int size = graph[cur_node].size();
        for (pair<int, int> next_info : graph[cur_node]) {
            long long next_cost = next_info.first;
            int next_node = next_info.second;

            if (distFromStart[next_node] > cur_cost + next_cost) {
                prevNode[next_node] = cur_node;
                distFromStart[next_node] = cur_cost + next_cost;
                dijkstra_queue.push({ distFromStart[next_node], next_node });
            }
        }
    }
}

void solution() {
    fill(&distFromStart[0], &distFromStart[n + 1], INF);

    int answer = 0;

    dijkstra(start_node);

    deque<int> minRoute;
    
    int cur_node = end_node;
    
    while (true) {
        minRoute.push_front(cur_node);
        if (cur_node == start_node) break;
        cur_node = prevNode[cur_node];
    }

    cout << distFromStart[end_node] << '\n';
    cout << minRoute.size() << '\n';;
    for (int cur_node : minRoute) {
        cout << cur_node << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        graph[a].push_back({ c, b });
    }

    cin >> start_node >> end_node;

    solution();
}
