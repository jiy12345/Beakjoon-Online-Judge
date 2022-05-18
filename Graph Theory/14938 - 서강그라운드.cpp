#include<iostream>
using namespace std;

#define MAX 100

int n, m, r;
int graph[MAX][MAX];
int items[MAX];


void floydWarshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int solution() {
    int answer = 0;

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    floydWarshall();

    for (int i = 1; i <= n; i++) {
        int cur_answer = 0;
        for (int j = 1; j <= n; j++)
            if (graph[i][j] <= m) cur_answer += items[j];

        answer = max(answer, cur_answer);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&graph[0][0], &graph[MAX - 1][MAX], MAX * 30);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        cin >> items[i];
    
    int a, b, l;
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;

        graph[a][b] = l;
        graph[b][a] = l;
    }

    cout << solution();
}
