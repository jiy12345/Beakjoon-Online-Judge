#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 소의 수
M: 통로의 개수
K: 모임에 참여하는 친구의 수

T: 테스트 케이스의 개수


- 변수 제한 사항
N: 1 ~ 100
M: ~ 6,000
K: 0 ~ N

각각의 소는 유일한 스킬 평가 수를 가지고 있음
경기 결과는 모순이 없다.

- 문제 상황
 각 테스트 케이스당 주어진 비용 내에서 목적지에 도달할 수 있는 가장 짧은 시간을 구하라

 만약 목적지에 도착할 수 없는 경우 Poor KCM을 출력하라.


2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

#define MAX 101

int N, M;

int graph[MAX][MAX];

void floydWarshall() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (graph[i][k] != 0 && graph[i][k] == graph[k][j])
                    graph[i][j] = graph[i][k];
}

int solution() {
    int answer = 0;

    floydWarshall();

    int numOfUnknownNodes;
    for (int i = 1; i <= N; i++) {
        numOfUnknownNodes = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (graph[i][j] == 0)
                numOfUnknownNodes++;
        }

        if (numOfUnknownNodes == 0) answer++;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = -1;
    }

    cout << solution();
}