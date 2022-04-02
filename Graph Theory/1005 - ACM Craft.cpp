#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
V: 정점의 개수
E: 간선의 개수
A, B, C: A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다.

- 변수 제한 사항
V: 1 ~ 10,000
E: 1 ~ 100,000

최소 스패닝 트리의 가중치가 int형으로 표현할 수 있는 범위가 되는 경우의 입력만 주어진다.

- 문제 상황
 최소 스패닝 트리의 가중치를 구하여라

2. 풀이 계획

최소 스패닝 트리를 구할 때는 경로를 따로 지정할 필요가 없으므로, 우선 순위 큐에 넣어 간선을 하나씩 빼고,

union find 알고리즘으로 양 쪽 다 연결되어 있을 때는 무시하고 넘어간다!

3. 계획 검증
*/

#define MAX 1001

// 필요한 변수 선언
int T, N, K, W; // 테스트 케이스의 개수, 건물의 개수, 건설 순서 규칙 개수, 목표 건물

int times[MAX]; // 건설에 걸리는 시간
int pre[MAX]; // 이전 노드의 개수
vector<int> suc[MAX]; // 이후 노드

int solution() {
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

        cout << solution() << '\n';
    }
}
