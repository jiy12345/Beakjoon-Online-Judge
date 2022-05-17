#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����

- ���� ���� ����

s: 1 ~ 50,000

����� ���� ���谡 ����� ���� ����.

- ���� ��Ȳ



2. Ǯ�� ��ȹ
 ���ͽ�Ʈ�� �˰����� ���� ����ؼ� �ּ� �ð��� ����ϵ�, �� �ܰ迡�� ����� �ʰ��Ǵ� ��δ� �������� �ʵ��� �Ѵ�!

3. ��ȹ ����
*/

#define MAX 21

int N;
int graph[MAX][MAX];
// true: ���� ����
// false: ���� ����
// �ϴ� ��� ��尣�� ���� �ִٰ� ����
bool road[MAX][MAX];

bool floydWarshall(void) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (i == j || j == k || i == k)
                    continue;
                // �÷��̵尡 �������� �ʴ� ���
                // �� ���� ������ �Ÿ��� �ִ� �Ÿ��� �ƴ� ���!
                else if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    return false;
                }
                // i -> j�� ���� ������ i -> k, k -> j ���� �ΰ��� ��ü�� �� ������,
                // �̷� ��� ������ ������ ���� �� ����
                else if (graph[i][j] == graph[i][k] + graph[k][j])
                    road[i][j] = true;
            }
    return true;
}

int solution() {
    int result = 0;

    if(!floydWarshall()) return -1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!road[i][j])
                result += graph[i][j];

    return result / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    cout << solution();
}
