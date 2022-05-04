#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
N: 학생의 수
M: 단방향 도로의 수
Ti: i번째 길을 지나는데 필요한 시간

- 변수 제한 사항
N: 1 ~ 1,000
M: 1 ~ 10,000
X:

- 감옥 관련 정보
 .: 빈 공간
 *: 지나갈 수 없는 벽
 #: 문
 $: 죄수의 위치

 상근이는 감옥 밖을 자유롭게 이동할 수 있다.
 죄수의 수는 항상 두명이다.
 각 죄수와 감옥의 바깥을 연결하는 경로가 항상 존재하는 경우만 입력으로 주어진다.


- 문제 상황
 죄수를 탈옥시키기 위해 열어야 하는 문의 최솟값을 출력하라!

2. 풀이 계획


3. 계획 검증
*/

#define INF 1e9 + 7

int N, M, X;
vector<pair<int, int>> graph[2][1001];
vector<int> distances[2];

void Dijstra(int k) {
    distances[k][X] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_queue;
    dijkstra_queue.push({ 0, X });

    while (!dijkstra_queue.empty()) {
        int cur_cost = dijkstra_queue.top().first;
        int cur_node = dijkstra_queue.top().second;
        dijkstra_queue.pop();

        if (cur_cost > distances[k][cur_node]) continue;

        for (int i = 0; i < graph[k][cur_node].size(); i++) {
            int next_node = graph[k][cur_node][i].second;
            int next_cost = cur_cost + graph[k][cur_node][i].first;

            if (next_cost < distances[k][next_node]) {
                distances[k][next_node] = next_cost;
                dijkstra_queue.push({ next_cost, next_node });
            }
        }
    }
}

int solution() {
    distances[0].resize(N + 1, INF);
    distances[1].resize(N + 1, INF);

    // 정점들에서 X로 가는 최단거리 계산
    Dijstra(1);

    // X에서 정점들로 가는 최단거리 계산
    Dijstra(0);

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, distances[0][i] + distances[1][i]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int u, v, t;
    cin >> N >> M >> X;

    // 원래 방향의 역방향으로도 간선을 기록해놓기
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> t;
        graph[0][u].push_back(make_pair(t, v));
        graph[1][v].push_back(make_pair(t, u));
    }

    cout << solution();

    return 0;
}
