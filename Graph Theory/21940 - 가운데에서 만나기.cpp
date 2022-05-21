#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����
M: ������ ����
K: ģ������ �� �ο�

T: �׽�Ʈ ���̽��� ����


- ���� ���� ����
N: 1 ~ 200
M: ~ N
K: 0 ~ N

������ �Ҵ� ������ ��ų �� ���� ������ ����
��� ����� ����� ����.

- ���� ��Ȳ
 �� �׽�Ʈ ���̽��� �־��� ��� ������ �������� ������ �� �ִ� ���� ª�� �ð��� ���϶�

 ���� �������� ������ �� ���� ��� Poor KCM�� ����϶�.


2. Ǯ�� ��ȹ
 ���ͽ�Ʈ�� �˰����� ���� ����ؼ� �ּ� �ð��� ����ϵ�, �� �ܰ迡�� ����� �ʰ��Ǵ� ��δ� �������� �ʵ��� �Ѵ�!

3. ��ȹ ����
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