#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 801
#define INF 200000 * 1000

int N, E;
int v1, v2;

vector<pair<int, int>> graph[MAX];
int distFrom1[MAX];
int distFromV1[MAX];
int distFromV2[MAX];

void dijkstra(int startNode, int *distFromStart) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_queue;
    
    dijkstra_queue.push({ 0, startNode });
    distFromStart[startNode] = 0;

    while (!dijkstra_queue.empty()) {
        int cur_cost = dijkstra_queue.top().first;
        int cur_node = dijkstra_queue.top().second;
        dijkstra_queue.pop();

        int size = graph[cur_node].size();
        for (pair<int, int> next_info: graph[cur_node]) {
            int next_cost = next_info.first;
            int next_node = next_info.second;

            if (distFromStart[next_node] > cur_cost + next_cost) {
                distFromStart[next_node] = cur_cost + next_cost;
                dijkstra_queue.push({ distFromStart[next_node], next_node });
            }
        }
    }
}

int solution() {
    fill(&distFrom1[0], &distFrom1[N + 1], INF);
    fill(&distFromV1[0], &distFromV1[N + 1], INF);
    fill(&distFromV2[0], &distFromV2[N + 1], INF);

    int answer = 0;

    dijkstra(1, distFrom1);
    dijkstra(v1, distFromV1);
    dijkstra(v2, distFromV2);

    int StoV1 = distFrom1[v1];
    int StoV2 = distFrom1[v2];

    int V1toV2 = distFromV1[v2];
    int V1toN = distFromV1[N];

    int V2toV1 = distFromV2[v1];
    int V2toN = distFromV2[N];

    
    int answer1 = StoV1 + V1toV2 + V2toN;
    int answer2 = StoV2 + V2toV1 + V1toN;

    answer = min(answer1, answer2);
    
    return (answer >= INF)? -1: answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }

    cin >> v1 >> v2;

    cout << solution();
}
