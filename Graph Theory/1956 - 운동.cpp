#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

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
