#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 도시의 개수
M: 도로의 개수
K: 친구들의 총 인원

T: 테스트 케이스의 개수


- 변수 제한 사항
N: 1 ~ 200
M: ~ N
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

#define MAX 201
#define INF MAX * (MAX - 1) * 1000

int N, M, K;

int graph[MAX][MAX];
int friends[MAX];

void floydWarshall() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

void solution() {
    floydWarshall();
    vector<int> answer;

    int minNum = INF;

    for (int i = 1; i <= N; i++) {
        int cur_maxNum = 0;
        for (int j = 0; j < K; j++) {
            if (graph[friends[j]][i] == INF || graph[i][friends[j]] == INF) {
                cur_maxNum = INF;
                break;
            }
            cur_maxNum = max(cur_maxNum, graph[friends[j]][i] + graph[i][friends[j]]);
        }
        if (minNum >= cur_maxNum) {
            if (minNum > cur_maxNum) {
                answer.clear();
                minNum = cur_maxNum;
            }
            answer.push_back(i);
        }

        cout << "i: " << i << ", cur_maxNum: " << cur_maxNum << ", minNum: " << minNum << endl;
    }

    for (int curNum : answer)
        cout << curNum << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&graph[0][0], &graph[MAX - 1][MAX], INF);

    cin >> N >> M;

    int A, B, T;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> T;

        graph[A][B] = T;
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> friends[i];
    }

    solution();
}