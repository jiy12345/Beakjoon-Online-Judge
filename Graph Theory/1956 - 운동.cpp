#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
V: 마을의 개수
E: 도로의 개수

- 변수 제한 사항
V: 2 ~ 400
M: 0 ~ V(V-1)

a, b쌍이 같은 도로가 여러번 주어지지 않는다.
두 마을간의 거리는 10,000 이하의 자연수이다.

- 문제 상황
 도로의 정보가 주어졌을 때, 도로의 길이의 합이 가장 작은 사이클을 찾아라.

 두 마을을 왕복하는 경우 또한 사이클에 포함된다.


2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

#define MAX 401
int INF = 5000000;

int V, E;

int graph[MAX][MAX];
int distFromStart[MAX][MAX];

void floydWarshall() {
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                distFromStart[i][j] = min(distFromStart[i][j], distFromStart[i][k] + distFromStart[k][j]);
}

int solution() {
    int answer = INF;

    fill(&distFromStart[0][0], &distFromStart[MAX - 1][MAX], INF);

    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            if (graph[i][j] != 0) distFromStart[i][j] = graph[i][j];

    floydWarshall();

    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            if (distFromStart[i][j] != INF && distFromStart[j][i] != INF)
                answer = min(answer, distFromStart[i][j] + distFromStart[j][i]);
            
        }

    return (answer == INF) ? -1 : answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;

        graph[a][b] = c;
    }

    cout << solution();
}
