#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1001

// 필요한 변수 선언
int T, N, K, W; // 테스트 케이스의 개수, 건물의 개수, 건설 순서 규칙 개수, 목표 건물



int solution(int times[MAX], int pre[MAX], vector<int> suc[MAX]) {
    int result[MAX] = { 0, };
    queue<int>Queue;

    // 이전에 지어야할 건물이 없는 건물부터 건설
    for (int i = 0; i < N; i++)
        if (!pre[i]) Queue.push(i);

    // W번 건물을 짓기위해 먼저 지어야 하는 건물이 없을 때
    while (pre[W] > 0) {
        int u = Queue.front();
        Queue.pop();
        // 다음 건물들의 건설 시간 갱신
        for (int next : suc[u]) {
            result[next] = max(result[next], result[u] + times[u]);
            if (--pre[next] == 0) Queue.push(next);
        }
    }
    // 현재까지 계산된 시간 + 목표 건물을 짓는 데 걸리는 시간
    return result[W] + times[W];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        int times[MAX]; // 건설에 걸리는 시간
        int pre[MAX] = { 0, }; // 이전 노드의 개수
        vector<int> suc[MAX]; // 이후 노드
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

        cout << solution(times, pre, suc) << '\n';
    }
}
