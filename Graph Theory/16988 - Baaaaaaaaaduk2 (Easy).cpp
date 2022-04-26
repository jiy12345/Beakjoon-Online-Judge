#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: �ٵ����� ���� ����
M: �ٵ����� ���� ����

- ���� ���� ����
N, M: 3, 20
0: ��ĭ
1: ���� ��
2: ����� ��

��ĭ�� 2�� �̻� ����
�� �÷��̾� ��� ������ ���� ��ƴ���� �������� �׷��� ������ ����

- ���� ��Ȳ
���� �ǿ��� �� 2���� �ξ� ���� �� �ִ� ��� ���� �ִ� ������ ����Ѵ�.

2. Ǯ�� ��ȹ

�� ��� ���� ���ִ� �κп� ���ؼ� Ž���ϵ�, �ֺ��� 0�� �������� üũ�Ѵ�.

0�� ������ �׻� 1�̻��� ���ۿ� ����.

���ƾ� �ϴ� ���� 1���� ���� 2���� ��� �� ������ üũ�ϸ� �� ���ϴ�.

1. ��� �湮���� ���� ��ġ�� ���� bfs�� �����Ͽ�, ���ִ� ��뵹�� ������, �� ���� ��� ���� ���ƾ� �ϴ� ���� ������ ���Ѵ�.
 => �ʿ��� ���� 3�� �̻��� ��� ���� �� ���� ���̹Ƿ� �������� �ʴ´�.
 => 1���� ���� 2���� ���� ���� �����Ѵ�.

// �̷��� �� ��� �� �� ������ ��ĭ�� �����ϴ� ��쿡 ���ؼ��� üũ���� ���Ѵ�.

���� ������ ���� �����غ���

1. ������ ��ǥ�� �̴´�.(�ֺ��� �ϳ��� ������� ���� �ִ� ��ĭ)

2. ���տ� ���� ���� 2�� ��ġ�Ѵ�.

3. �� ���� ��ġ �� �� ���� 4�������κ����� bfs�� �����ϰ�, ������ �ѷ��ο� ���� ���(0�� ������ ���� ���)���� ���� ���� ���Ѵ�.

3. ��ȹ ����
*/

#define MAX 20

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

int N, M;
int board[MAX][MAX];
bool isVisited[MAX][MAX];

bool isInRange(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int bfs(int start_i, int start_j) {
    int numStonesCanBeCaught = 0;

    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({ start_i, start_j });
    isVisited[start_i][start_j] = true;

    while (!bfs_queue.empty()) {
        int cur_i = bfs_queue.front().first;
        int cur_j = bfs_queue.front().second;
        if(numStonesCanBeCaught != -1) numStonesCanBeCaught++;
        bfs_queue.pop();

        for (int i = 0; i < 4; i++) {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];

            if (isInRange(next_i, next_j) == false || isVisited[next_i][next_j] == true) continue;

            if (board[next_i][next_j] == 0) {
                cout << "?" << endl;
                numStonesCanBeCaught = -1;
            }
            else if (board[next_i][next_j] == 2) {
                isVisited[next_i][next_j] = true;
                bfs_queue.push({ next_i, next_j });
            }
        }
    }

    return (numStonesCanBeCaught == -1) ? 0 : numStonesCanBeCaught;
}

int solution() {
    int answer = 0;

    vector<pair<int, int>> possibleLocations;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // ��ĭ�� ���� ������
            if (board[i][j] != 0) continue;

            for (int k = 0; k < 4; k++) {
                int next_i = i + di[k];
                int next_j = j + dj[k];
                if (isInRange(next_i, next_j) == false) continue;
                // ����� ���� �ֺ��� ���� ��� ���
                if (board[next_i][next_j] == 2) {
                    possibleLocations.push_back({ i, j });
                    break;
                }
            }
        }
    }

    if (possibleLocations.size() == 1) {
        board[possibleLocations[0].first][possibleLocations[0].second] = 1;

        for (int l = 0; l < 4; l++) {
            int next_i = possibleLocations[0].first + di[l];
            int next_j = possibleLocations[0].second + dj[l];
            if (isInRange(next_i, next_j) == false) continue;
            // ����� ���� ���� ���
            if (isVisited[next_i][next_j] == false && board[next_i][next_j] == 2) {
                answer += bfs(next_i, next_j);
            }
        }
    }

    for (int i = 0; i < possibleLocations.size(); i++) {
        for (int j = i + 1; j < possibleLocations.size(); j++) {
            int curCaughtStones = 0;

            // �湮 �迭 �ʱ�ȭ
            memset(isVisited, false, sizeof(isVisited));

            pair<int, int> twoLocations[2] = { possibleLocations[i], possibleLocations[j] };
            
            // �ӽ÷� �� ����
            board[twoLocations[0].first][twoLocations[0].second] = 1;
            board[twoLocations[1].first][twoLocations[1].second] = 1;

            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 4; l++) {
                    int next_i = twoLocations[k].first + di[l];
                    int next_j = twoLocations[k].second + dj[l];
                    if (isInRange(next_i, next_j) == false) continue;
                    // ����� ���� ���� ���
                    if (isVisited[next_i][next_j] == false && board[next_i][next_j] == 2) {
                        curCaughtStones += bfs(next_i, next_j);
                    }
                }
            }

            // ���� �� �ٽ� ����
            board[twoLocations[0].first][twoLocations[0].second] = 0;
            board[twoLocations[1].first][twoLocations[1].second] = 0;

            answer = max(answer, curCaughtStones);
        }
    }

    return answer;
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

    cout << solution();
}
