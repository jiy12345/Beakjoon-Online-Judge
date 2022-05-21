#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
    vector<int> answer;

    floydWarshall();

    for (int i = 1; i <= N; i++) {
        graph[i][i] = 0;
    }

    int minNum = INF;

    for (int i = 1; i <= N; i++) {
        int cur_maxNum = 0;
        for (int j = 0; j < K; j++) {
            cur_maxNum = max(cur_maxNum, graph[friends[j]][i] + graph[i][friends[j]]);
        }
        if (minNum >= cur_maxNum) {
            if (minNum > cur_maxNum) {
                answer.clear();
                minNum = cur_maxNum;
            }
            answer.push_back(i);
        }
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
