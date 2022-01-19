#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int Arctic[300][300];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

void bfs(int tempArctic[][300], pair<int, int> startLocation) {
    queue<pair<int, int>> bfs_queue;

    bfs_queue.push(startLocation);

    while (!bfs_queue.empty()) {
        int cur_i = bfs_queue.front().first;
        int cur_j = bfs_queue.front().second;
        bfs_queue.pop();

        for (int i = 0; i < 4; i++) {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];

            if (tempArctic[next_i][next_j] != 0) {
                tempArctic[next_i][next_j] = 0;

                bfs_queue.push(make_pair(next_i, next_j));
            }
        }
    }
}

int icebergExploration(int tempArctic[][300]) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempArctic[i][j] != 0) {
                count++;
                bfs(tempArctic, make_pair(i, j));;
            }
        }
    }

    return count;
}

int solution() {
    int year = 0;

    while (true) {
        year++;

        // 빙산 녹는 과정
        int tempArctic[300][300];
        bool isIceberg = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 테두리에는 빙산이 존재하지 않으므로 제외하고 진행
                if (i == 0 || j == 0) {
                    tempArctic[i][j] = 0;
                }
                else {
                    if (Arctic[i][j] != 0) {
                        isIceberg = true;

                        int numOfSeaTile = 0;
                        for (int k = 0; k < 4; k++) {
                            int next_i = i + di[k];
                            int next_j = j + dj[k];

                            if (Arctic[next_i][next_j] == 0) {
                                numOfSeaTile++;
                            }
                        }
                        tempArctic[i][j] = max(0, Arctic[i][j] - numOfSeaTile);
                    }
                    else {
                        tempArctic[i][j] = 0;
                    }
                }
            }
        }

        if (isIceberg == false) {
            return 0;
        }

        // 내용 배열에 반영하기
        copy(&tempArctic[0][0], &tempArctic[0][0] + 300 * 300, &Arctic[0][0]);

        // 탐색하는 과정
        if (icebergExploration(tempArctic) >= 2) {
            break;
        }
    }

    return year;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // cout << "i: " << i << ", j: " << j << endl;
            cin >> Arctic[i][j];
        }
    }

    cout << solution();

    return 0;
}
