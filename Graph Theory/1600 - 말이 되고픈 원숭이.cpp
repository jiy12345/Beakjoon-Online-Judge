#include<iostream>
#include<queue>
using namespace std;

#define MAX 200

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };
int horseMove_di[8] = { -2, -2, -1, +1, +2, +2, +1, -1 };
int horseMove_dj[8] = { -1, +1, +2, +2, +1, -1, -2, -2 };

int K, W, H;
int grid[MAX][MAX];
bool remainedHorseMoves[MAX][MAX][31];

bool isInRange(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int solution() {
    queue<vector<int>> bfs_queue;
    bfs_queue.push({ 0, 0, 0, K });

    int answer = -1;

    while (!bfs_queue.empty()) {
        int cur_depth = bfs_queue.front()[0];
        int cur_i = bfs_queue.front()[1];
        int cur_j = bfs_queue.front()[2];
        int cur_remainedhHorseMoves = bfs_queue.front()[3];
        bfs_queue.pop();

        if (cur_i == H - 1 && cur_j == W - 1) {
            answer = cur_depth;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];

            if (isInRange(next_i, next_j) == false || grid[next_i][next_j] == 1) continue;

            if (remainedHorseMoves[next_i][next_j][cur_remainedhHorseMoves] == false) {
                remainedHorseMoves[next_i][next_j][cur_remainedhHorseMoves] = true;
                bfs_queue.push({ cur_depth + 1, next_i, next_j, cur_remainedhHorseMoves });
            }
        }

        if (cur_remainedhHorseMoves == 0) continue;

        for (int i = 0; i < 8; i++) {
            int next_i = cur_i + horseMove_di[i];
            int next_j = cur_j + horseMove_dj[i];

            if (isInRange(next_i, next_j) == false || grid[next_i][next_j] == 1) continue;

            if (remainedHorseMoves[next_i][next_j][cur_remainedhHorseMoves - 1] == false) {
                remainedHorseMoves[next_i][next_j][cur_remainedhHorseMoves - 1] = true;
                bfs_queue.push({ cur_depth + 1, next_i, next_j, cur_remainedhHorseMoves - 1 });
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    cout << solution();
}
