#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>
using namespace std;

/*
1. 문제 분석
- 변수
n: 도시의 개수
m: 버스(간선)의 개수


- 변수 제한 사항
n: 1 ~ 1,000
m: 1 ~ 100,000

버스 비용: 100,000
항상 시작점에서 도착점으로 가는 경로가 존재한다.

- 문제 상황
 그래프의 상황, 시작점과 도착점이 주어졌을 때,

 최소비용을 갖는 경로에 포함되어 있는 도시의 개수, 경로를 출력한다.




2. 풀이 계획

1, v1, v2 지점에서의 다익스트라를 진행한 후,

경로가 있을 경우에만
1 -> v1
v1 -> v2
v2 -> N
거리의 합을 더한 값을 출력하면 될 듯 하다.

3. 계획 검증
*/

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
