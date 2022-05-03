#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
T: �׽�Ʈ ���̽��� ����
N: ����(���)�� ��
M: �� ���� ���
K: Ƽ�� ����(����)�� ��


- ���� ���� ����
N: 2 ~ 100
M: 0 ~ 10,000
K: 0 ~ 10,000

u: �� Ƽ���� ��� ����
v: �� Ƽ���� ���� ����
c: ���µ� ��� ��� / 1 ~ M
d: �ҿ�ð� / 1 ~ 1,000

��ߵ��ô� 1���̰�, ���� ���ô� N���̴�!

- ���� ��Ȳ
 �� �׽�Ʈ ���̽��� �־��� ��� ������ �������� ������ �� �ִ� ���� ª�� �ð��� ���϶�

 ���� �������� ������ �� ���� ��� Poor KCM�� ����϶�.


2. Ǯ�� ��ȹ
 ���ͽ�Ʈ�� �˰����� ���� ����ؼ� �ּ� �ð��� ����ϵ�, �� �ܰ迡�� ����� �ʰ��Ǵ� ��δ� �������� �ʵ��� �Ѵ�!

3. ��ȹ ����
*/

#define MAX 101
#define MAX_COST 10001
#define INF 10000 * 100

// �ʿ��� ���� ����
int T;
int N, M, K; // �׽�Ʈ ���̽��� ����, �ǹ��� ����, �Ǽ� ���� ��Ģ ����, ��ǥ �ǹ�

struct Edge {
    int destNode;
    int time;
    int cost;
};

vector<vector<Edge>> edges;
int dp[MAX][MAX_COST];


void dijkstra(int start) {

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({ 0, 1, 0 }); // time, node, cost
    dp[1][0] = 0;

    while (!pq.empty()) {
        int curTime = pq.top()[0];
        int curNode = pq.top()[1];
        int curCost = pq.top()[2];
        pq.pop();

        // ���� ������� �� ���� �ð� ���� �̹� �湮�ߴٸ� Ž�� X
        if (dp[curNode][curCost] < curTime) continue;

        for (int i = 0; i < edges[curNode].size(); i++) {
            int next = edges[curNode][i].destNode;
            int next_time = curTime + edges[curNode][i].time;
            int next_cost = curCost + edges[curNode][i].cost;
 
            if (next_cost <= M && next_time < dp[next][next_cost]) {
                for (int j = next_cost + 1; j <= M; j++) {
                    if (dp[next][j] <= next_time) break;
                    dp[next][j] = next_time;
                }

                dp[next][next_cost] = next_time;
                pq.push({ next_time, next, next_cost });
            }
        }

    }
}

string solution() {
    int answer = INF;

    dijkstra(1);

    // ������ ��� ������ �ּ� �ð��� �ɸ� ��� ã��
    for (int i = 0; i <= M; i++)
        answer = min(answer, dp[N][i]);

    return (answer == INF) ? "Poor KCM" : to_string(answer);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K;
        // �迭 �ʱ�ȭ  
        edges.clear();
        edges.resize(N + 1);

        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++)
                dp[i][j] = INF;

        int u;
        for (int i = 0; i < K; i++) {
            Edge edge;

            cin >> u >> edge.destNode >> edge.cost >> edge.time;

            edges[u].push_back(edge);
        }

        cout << solution() << '\n';
    }
}
