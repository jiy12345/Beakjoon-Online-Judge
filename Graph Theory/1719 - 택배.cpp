#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 201
#define INF 9e8

int N, M;
int dist[MAX][MAX];
int path[MAX][MAX];

void floyd_warshall() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if (i != k) path[i][j] = path[i][k];
                }
            }
}

void solution() {
    floyd_warshall();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (path[i][j]) cout << path[i][j] << " ";
            else cout << "- ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    fill(&dist[0][0], &dist[MAX - 1][MAX], INF);
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
        path[a][b] = b;
        path[b][a] = a;
    }

    solution();
}