#include<iostream>
#include<queue>
using namespace std;

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
            // 빈칸일 때만 따지기
            if (board[i][j] != 0) continue;

            for (int k = 0; k < 4; k++) {
                int next_i = i + di[k];
                int next_j = j + dj[k];
                if (isInRange(next_i, next_j) == false) continue;
                // 상대편 돌이 주변에 있을 경우 고려
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
            // 상대편 돌일 때만 고려
            if (isVisited[next_i][next_j] == false && board[next_i][next_j] == 2) {
                answer += bfs(next_i, next_j);
            }
        }
    }

    for (int i = 0; i < possibleLocations.size(); i++) {
        for (int j = i + 1; j < possibleLocations.size(); j++) {
            int curCaughtStones = 0;

            // 방문 배열 초기화
            memset(isVisited, false, sizeof(isVisited));

            pair<int, int> twoLocations[2] = { possibleLocations[i], possibleLocations[j] };
            
            // 임시로 돌 놓기
            board[twoLocations[0].first][twoLocations[0].second] = 1;
            board[twoLocations[1].first][twoLocations[1].second] = 1;

            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 4; l++) {
                    int next_i = twoLocations[k].first + di[l];
                    int next_j = twoLocations[k].second + dj[l];
                    if (isInRange(next_i, next_j) == false) continue;
                    // 상대편 돌일 때만 고려
                    if (isVisited[next_i][next_j] == false && board[next_i][next_j] == 2) {
                        curCaughtStones += bfs(next_i, next_j);
                    }
                }
            }

            // 놨던 돌 다시 빼기
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
