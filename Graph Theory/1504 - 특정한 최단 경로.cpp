#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 정점의 개수
E: 간선의 개수

a, b, c: a번 정점에서 b번 정점까지 양방향 길이가 존재하며, 그 거리가 c

v1, v2: 반드시 거쳐야 하는 두개의 서로 다른 정점 번호

- 변수 제한 사항
N: 2 ~ 800
E: 0 ~ 200,000

c: 1 ~ 1,000

v1, v2은 같은 정점이 아니다.

- 문제 상황
 1번 정점에서 N번 정점으로 가는 최단 경로를 구하되, 주어진 임의의 정점을 2개 거쳐 가는 경로의 길이를 구하라

 한번 이동했던 정점, 간선 모두 다시 이동할 수 있다.

 만약 그러한 경로가 없다면 -1을 출력하라!



2. 풀이 계획

1, v1, v2 지점에서의 다익스트라를 진행한 후, 

경로가 있을 경우에만
1 -> v1
v1 -> v2
v2 -> N
거리의 합을 더한 값을 출력하면 될 듯 하다.

3. 계획 검증
*/

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
