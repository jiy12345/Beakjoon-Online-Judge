#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 바둑판의 행의 개수
M: 바둑판의 열의 개수

- 변수 제한 사항
N, M: 3, 20
0: 빈칸
1: 나의 돌
2: 상대의 돌

빈칸은 2개 이상 존재
양 플레이어 모두 상대방의 돌로 빈틈없이 에워싸인 그룹이 없음이 보장

- 문제 상황
현재 판에서 돌 2개를 두어 죽일 수 있는 상대 돌의 최대 갯수를 출력한다.

2. 풀이 계획

각 상대 돌이 모여있는 부분에 대해서 탐색하되, 주변의 0의 개수까지 체크한다.

0의 개수는 항상 1이상일 수밖에 없다.

놓아야 하는 돌이 1개일 경우와 2개일 경우 두 가지만 체크하면 될 듯하다.

1. 모든 방문하지 않은 위치에 대해 bfs를 진행하여, 모여있는 상대돌의 개수와, 그 돌을 잡기 위해 놓아야 하는 돌의 개수를 구한다.
 => 필요한 돌이 3개 이상일 경우 잡을 수 없는 것이므로 저장하지 않는다.
 => 1개일 경우와 2개일 경우는 따로 저장한다.

// 이렇게 할 경우 두 돌 무리가 빈칸을 공유하는 경우에 대해서는 체크하지 못한다.

따라서 다음과 같이 진행해보자

1. 가능한 좌표를 뽑는다.(주변에 하나라도 상대편의 돌이 있는 빈칸)

2. 조합에 따라 돌을 2개 배치한다.

3. 각 돌을 배치 후 각 돌의 4방향으로부터의 bfs를 진행하고, 완전히 둘러싸여 있을 경우(0이 나오지 않을 경우)에만 잡힌 돌로 더한다.

3. 계획 검증
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
