#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
K: 말을 따라할 수 있는 횟수
W, H: 격자판의 가로길이, 세로길이​

- 변수 제한 사항
K: 0 ~ 30
W, H: 1 ~ 200​

0: 평지
1: 장애물

- 문제 상황
격자판의 상태가 주어졌을 때, 원숭이 동작수의 최솟값을 구하여라.​

2. 풀이 계획

그런데 개수에 따라 집중국의 범위는 매우 달라지기가 쉽다. 그렇다면 어떻게 해야할까?

​

 일단 좌표 순으로 먼저 정리를 진행하고, 각 좌표간의 거리를 구하여 배열에 저장해놓는다.

이 때 거리의 합을 모두 구하면 전체 범위가 되며, 거리 하나를 제거한다는 것은 원래 하나였던 범위가 둘로 나눠진다는 것을 의미하고, 범위가 둘로 나눠진다는 것은 집중국이 하나 더 생긴다는 것을 의미한다.

​

 따라서 집중국의 개수를 합이 최소가 되는 K개로 맞추기 위해서는 인접한 좌표간의 거리를 모두 구한 후 거리에 대해 정렬하고, 최대 거리쪽부터 (집중국의 개수(K) - 1)개 만큼 거리를 제거하고, 거리 배열의 모든 원소를 합하면 답이 나올 듯 하다!

​

3. 계획 검증

 1. 알고리즘 측면

 알고리즘 측면에소 크게 문제가 될 부분은 보이지 않았다.

​

 2. 시간복잡도 측면

 시간 복잡도 측면에서는 좌표를 정렬하는 부분이 시간복잡도가 가장 높으며, C++의 sort 함수는 O(NlogN)의 시간복잡도를 보이므로, 10,000의 크기에 대해서는 문제 없이 동작할 듯 하다!

​

 3. 공간복잡도 측면

*/

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