#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
n: 건물(정점)의 수
m: 길(간선)의 수

u, v, b: u에서 v로 가는 길(b = 1 : 양방향, b = 0 : 일방통행)

- 변수 제한 사항
n: 1 ~ 250
m: 

- 문제 상황
예은이가 얻을 수 있는 최대 아이템 개수를 출력한다.

2. 풀이 계획
일단 가장 쉽게 생각했을 경우, 각 정점에 불을 붙였을 때 가장 늦게 타게 되는 부분은
현재 정점으로부터 가장 먼 정점에서 가장 긴 간선으로 이동했을 때이다.

=> 생각해보니 이렇게 해서는 알 수 없다. 간선이 더 길어지는 경우가 생길 수 있기 때문이다.

따라서 가능한 후보군은, 가장 긴 간선으로 이동하여 각 간선으로부터 가장 긴 간선을 태우는데 드는 시간이라고 볼 수 있나?

1. 각 정점까지 최단 거리를 통해 태운다고 본다.
2. 각 정점으로부터 연결된 간선(출발점과의 간선 포함)
 => 어느 간선을 통해 왔는지는 어떻게 체크함?
 => 어차피 최단 거리보다는 길지 않으려나


3. 계획 검증
*/

#define MAX 251

int n, m, k;
int graph[MAX][MAX];
int items[MAX];


void floydWarshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j) graph[i][j] = 0;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
                
}

void solution() {
    int answer = 0;

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    floydWarshall();

    cin >> k;

    for (int i = 0, u, v; i < k; i++) {
        cin >> u >> v;
        cout << graph[u][v] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&graph[0][0], &graph[MAX - 1][MAX], MAX * MAX);

    cin >> n >> m;

    for (int i = 0, u, v, b; i < m; i++) {
        cin >> u >> v >> b;
        graph[u][v] = 0;
        if (!b) graph[v][u] = 1;
        if (b) graph[v][u] = 0;
    }

    solution();
}
