#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 물건의 개수
M: 측정된 물건 쌍의 개수

- 변수 제한 사항
N: 5 ~ 100
M: 0 ~ 2000

- 문제 상황
 


2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

#define MAX 101
int INF = 1000;

int N, M;

int Greater[MAX][MAX];
int Smaller[MAX][MAX];

void floydWarshall(int distFromStart[][MAX]) {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                distFromStart[i][j] = min(distFromStart[i][j], distFromStart[i][k] + distFromStart[k][j]);
}

void solution() {
    floydWarshall(Greater);
    floydWarshall(Smaller);

    int numOfNodes;
    for (int i = 1; i <= N; i++) {
        numOfNodes = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (Greater[i][j] + Smaller[i][j] == 2 * INF)
                numOfNodes++;
        }

        cout << numOfNodes << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    fill(&Greater[0][0], &Greater[MAX - 1][MAX], INF);
    fill(&Smaller[0][0], &Smaller[MAX - 1][MAX], INF);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        Greater[a][b] = 1;
        Smaller[b][a] = 1;
    }

    solution();
}
