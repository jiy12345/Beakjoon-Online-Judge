#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� ��
M: ����� ����
K: ���ӿ� �����ϴ� ģ���� ��

T: �׽�Ʈ ���̽��� ����


- ���� ���� ����
N: 1 ~ 100
M: ~ 6,000
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