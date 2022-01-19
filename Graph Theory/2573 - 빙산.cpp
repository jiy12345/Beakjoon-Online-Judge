#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N, M: 배열의 행의 개수와 열의 개수

- 변수 제한 사항
N, M: 3~300
각 칸에 들어가는 값: 0~10
빙산이 차지하는 칸의 개수: 10,000이하

배열의 테두리는 항상 0이다.

- 문제 상황
 2차원 배열 상에서 동서남북 방향으로 붙어있는 칸들은 한 덩이라고 보고, 
 한덩어리의 빙산이 주어질 때 이 빙산이 두 덩어리 이상으롭 분리되는 최초의 시간을 구하여라.

2. 풀이 계획

다음과 같은 과정을 거치면 될 듯 하다.

1. 입력 받는다.
2. count의 초기값을 0으로 설정한 후 다음을 반복한다.
 1) count를 1 증가 시킨 후, 빙산을 녹이는 과정을 진행한다.
  => 이 때 녹는 과정에서 녹은 빙산의 상황이 같은 시간대의 다른 빙산이 녹는 과정에 반영되면 안되므로, 새로운 2차원 배열에 작성한다!
 2) push할 때 방문 표시(0으로 표시하자)하는 BFS를 통해, 덩어리의 개수를 구하자!
3. 2-2)에서 덩어리의 개수가 2 이상이면 빠져나가며 count를 반환한다.
3. 계획 검증

*/

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
