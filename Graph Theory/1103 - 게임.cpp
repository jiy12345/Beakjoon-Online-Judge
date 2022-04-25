#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� ũ��
M: ���� ũ��
H: ����

- ���� ���� ����
N, M: 1 ~ 50
�����ִ� ����: 1 ~ 9
���� ���� ĭ�� ������ �ƴ�

- ���� ��Ȳ
 �ִ� ��� ������ ������ �� �ִ��� ���Ͽ���.
 ������ ���ѹ� ������ �� �ִٸ� -1�� ����϶�

2. Ǯ�� ��ȹ
 �� ��ġ������ �ִ밪�� �����س���, �� ū ���� ���� ��� ����
 => �̹� ���� ���� ���� ��� �� �� ��ȯ�ϵ��� ��

 ���� ��λ� �ִ� ��忡 �ٽ� �湮�ϰ� �� ��� ����Ŭ �߻�
 => ������ �� �� �����Ƿ� -1  ����ϵ��� ��

3. ��ȹ ����
*/

#define MAX 50

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

int N, M;
char board[MAX][MAX];
int maxMovementFrom[MAX][MAX];
bool isVisited[MAX][MAX];

bool isInRange(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int dfs(int cur_i, int cur_j) {
    // �����̰ų� ������ ����� ���
    if (board[cur_i][cur_j] == 'H' || !isInRange(cur_i, cur_j)) return 0;
    // ����Ŭ�� ���
    if (isVisited[cur_i][cur_j]) return -1;
    // �̹� ���� ���� ���� ���
    if (maxMovementFrom[cur_i][cur_j] != 0) return maxMovementFrom[cur_i][cur_j];

    // ����Ŭ üũ�� ���� �湮 ǥ��
    isVisited[cur_i][cur_j] = true;

    for (int i = 0; i < 4; i++) {
        int next_i = cur_i + di[i] * (board[cur_i][cur_j] - '0');
        int next_j = cur_j + dj[i] * (board[cur_i][cur_j] - '0');

        int next_num = dfs(next_i, next_j);

        // ���� �������� ����Ŭ�� �߰ߵǾ��� ���
        if (next_num == -1) return -1;

        maxMovementFrom[cur_i][cur_j] = max(maxMovementFrom[cur_i][cur_j], next_num + 1);
    }

    isVisited[cur_i][cur_j] = false;

    return maxMovementFrom[cur_i][cur_j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0);
}
