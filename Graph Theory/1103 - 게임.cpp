#include<iostream>
using namespace std;

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
    // 구멍이거나 범위를 벗어났을 경우
    if (board[cur_i][cur_j] == 'H' || !isInRange(cur_i, cur_j)) return 0;
    // 사이클일 경우
    if (isVisited[cur_i][cur_j]) return -1;
    // 이미 계산된 값이 있을 경우
    if (maxMovementFrom[cur_i][cur_j] != 0) return maxMovementFrom[cur_i][cur_j];

    // 사이클 체크를 위한 방문 표시
    isVisited[cur_i][cur_j] = true;

    for (int i = 0; i < 4; i++) {
        int next_i = cur_i + di[i] * (board[cur_i][cur_j] - '0');
        int next_j = cur_j + dj[i] * (board[cur_i][cur_j] - '0');

        int next_num = dfs(next_i, next_j);

        // 이후 과정에서 사이클이 발견되었을 경우
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
