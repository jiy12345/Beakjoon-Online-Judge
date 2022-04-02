#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
V: ������ ����
E: ������ ����
A, B, C: A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ� �ִ�.

- ���� ���� ����
V: 1 ~ 10,000
E: 1 ~ 100,000

�ּ� ���д� Ʈ���� ����ġ�� int������ ǥ���� �� �ִ� ������ �Ǵ� ����� �Է¸� �־�����.

- ���� ��Ȳ
 �ּ� ���д� Ʈ���� ����ġ�� ���Ͽ���

2. Ǯ�� ��ȹ

�ּ� ���д� Ʈ���� ���� ���� ��θ� ���� ������ �ʿ䰡 �����Ƿ�, �켱 ���� ť�� �־� ������ �ϳ��� ����,

union find �˰������� �� �� �� ����Ǿ� ���� ���� �����ϰ� �Ѿ��!

3. ��ȹ ����
*/

#define MAX 1001

// �ʿ��� ���� ����
int T, N, K, W; // �׽�Ʈ ���̽��� ����, �ǹ��� ����, �Ǽ� ���� ��Ģ ����, ��ǥ �ǹ�

int times[MAX]; // �Ǽ��� �ɸ��� �ð�
int pre[MAX]; // ���� ����� ����
vector<int> suc[MAX]; // ���� ���

int solution() {
    int result[MAX] = { 0, };
    queue<int>Queue;

    // ������ ������� �ǹ��� ���� �ǹ����� �Ǽ�
    for (int i = 0; i < N; i++)
        if (!pre[i]) Queue.push(i);

    // W�� �ǹ��� �������� ���� ����� �ϴ� �ǹ��� ���� ��
    while (pre[W] > 0) {
        int u = Queue.front();
        Queue.pop();
        // ���� �ǹ����� �Ǽ� �ð� ����
        for (int next : suc[u]) {
            result[next] = max(result[next], result[u] + times[u]);
            if (--pre[next] == 0) Queue.push(next);
        }
    }
    // ������� ���� �ð� + ��ǥ �ǹ��� ���� �� �ɸ��� �ð�
    return result[W] + times[W];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            cin >> times[i];
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            suc[X - 1].push_back(Y - 1);
            pre[Y - 1]++;
        }
        cin >> W;
        W--;

        cout << solution() << '\n';
    }
}
