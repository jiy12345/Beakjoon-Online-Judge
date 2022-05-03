#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
T: 테스트 케이스의 개수
N: 공항(노드)의 수
M: 총 지원 비용
K: 티켓 정보(간선)의 수


- 변수 제한 사항
N: 2 ~ 100
M: 0 ~ 10,000
K: 0 ~ 10,000

u: 각 티켓의 출발 공항
v: 각 티켓의 도착 공항
c: 가는데 드는 비용 / 1 ~ M
d: 소요시간 / 1 ~ 1,000

출발도시는 1번이고, 도착 도시는 N번이다!

- 문제 상황
 각 테스트 케이스당 주어진 비용 내에서 목적지에 도달할 수 있는 가장 짧은 시간을 구하라

 만약 목적지에 도착할 수 없는 경우 Poor KCM을 출력하라.


2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

#define MAX 101
#define MAX_COST 10001
#define INF 10000 * 100

// 필요한 변수 선언
int T;
int N, M, K; // 테스트 케이스의 개수, 건물의 개수, 건설 순서 규칙 개수, 목표 건물

struct Edge {
    int destNode;
    int time;
    int cost;
};

vector<vector<Edge>> edges;
int dp[MAX][MAX_COST];


void dijkstra(int start) {

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({ 0, 1, 0 }); // time, node, cost
    dp[1][0] = 0;

    while (!pq.empty()) {
        int curTime = pq.top()[0];
        int curNode = pq.top()[1];
        int curCost = pq.top()[2];
        pq.pop();

        // 같은 비용으로 더 적은 시간 내에 이미 방문했다면 탐색 X
        if (dp[curNode][curCost] < curTime) continue;

        for (int i = 0; i < edges[curNode].size(); i++) {
            int next = edges[curNode][i].destNode;
            int next_time = curTime + edges[curNode][i].time;
            int next_cost = curCost + edges[curNode][i].cost;
 
            if (next_cost <= M && next_time < dp[next][next_cost]) {
                for (int j = next_cost + 1; j <= M; j++) {
                    if (dp[next][j] <= next_time) break;
                    dp[next][j] = next_time;
                }

                dp[next][next_cost] = next_time;
                pq.push({ next_time, next, next_cost });
            }
        }

    }
}

string solution() {
    int answer = INF;

    dijkstra(1);

    // 가능한 비용 내에서 최소 시간이 걸린 경로 찾기
    for (int i = 0; i <= M; i++)
        answer = min(answer, dp[N][i]);

    return (answer == INF) ? "Poor KCM" : to_string(answer);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K;
        // 배열 초기화  
        edges.clear();
        edges.resize(N + 1);

        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++)
                dp[i][j] = INF;

        int u;
        for (int i = 0; i < K; i++) {
            Edge edge;

            cin >> u >> edge.destNode >> edge.cost >> edge.time;

            edges[u].push_back(edge);
        }

        cout << solution() << '\n';
    }
}
