#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
n: �ǹ�(����)�� ��
m: ��(����)�� ��

u, v, b: u���� v�� ���� ��(b = 1 : �����, b = 0 : �Ϲ�����)

- ���� ���� ����
n: 1 ~ 250
m: 

- ���� ��Ȳ
�����̰� ���� �� �ִ� �ִ� ������ ������ ����Ѵ�.

2. Ǯ�� ��ȹ
�ϴ� ���� ���� �������� ���, �� ������ ���� �ٿ��� �� ���� �ʰ� Ÿ�� �Ǵ� �κ���
���� �������κ��� ���� �� �������� ���� �� �������� �̵����� ���̴�.

=> �����غ��� �̷��� �ؼ��� �� �� ����. ������ �� ������� ��찡 ���� �� �ֱ� �����̴�.

���� ������ �ĺ�����, ���� �� �������� �̵��Ͽ� �� �������κ��� ���� �� ������ �¿�µ� ��� �ð��̶�� �� �� �ֳ�?

1. �� �������� �ִ� �Ÿ��� ���� �¿�ٰ� ����.
2. �� �������κ��� ����� ����(��������� ���� ����)
 => ��� ������ ���� �Դ����� ��� üũ��?
 => ������ �ִ� �Ÿ����ٴ� ���� ��������


3. ��ȹ ����
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
