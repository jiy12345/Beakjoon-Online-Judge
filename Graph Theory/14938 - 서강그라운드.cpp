#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
n: 지역(노드)의 개수
m: 수색 범위
r: 길(간선)의 개수
t: 각 구역에 있는 아이템의 수

l: 길의 길이

- 변수 제한 사항
n: 1 ~ 100
m: 1 ~ 15
r: 1 ~ 100
t: 1 ~ 30

l: 1 ~ 15


- 문제 상황
예은이가 얻을 수 있는 최대 아이템 개수를 출력한다.

2. 풀이 계획
일단 가장 쉽게 생각했을 경우, 각 정점에 불을 붙였을 때 가장 늦게 타게 되는 부분은 
현재 정점으로부터 가장 먼 정점에서 가장 긴 간선으로 이동했을 때이다.

=> 생각해보니 이렇게 해서는 알 수 없다. 간선이 더 길어지는 경우가 생길 수 있기 때문이다.

따라서 가능한 후보군은, 가자


3. 계획 검증
*/

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
