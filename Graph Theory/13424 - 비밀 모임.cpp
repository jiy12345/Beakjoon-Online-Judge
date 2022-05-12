#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 101
#define INF 6000 * 1000

// 필요한 변수 선언
int T;
int N, M, K;

vector<pair<int ,int>> graph[MAX];
vector<int> startLocations;
int distFromStart[MAX][MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, start });
    distFromStart[start][start] = 0;

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 같은 비용으로 더 적은 시간 내에 이미 방문했다면 탐색 X
        if (distFromStart[start][cur_node] < cur_dist) continue;

        for (pair<int, int> next_info : graph[cur_node]) {
            int next_dist = next_info.first;
            int next_node = next_info.second;

            if (cur_dist + next_dist < distFromStart[start][next_node]) {
                distFromStart[start][next_node] = cur_dist + next_dist;
                pq.push({ distFromStart[start][next_node], next_node });
            }
        }
    }
}

int solution() {
    fill(&distFromStart[0][0], &distFromStart[MAX - 1][MAX], INF);

    int min_num = INF;
    int min_location = 0;

    for (int curStartLocation: startLocations) {
        dijkstra(curStartLocation);
    }

    // 모든 도착점에 대해 반복
    for (int i = 1; i <= N; i++) {
        int curSum = 0;

        // 모든 출발점에서의 거리 고려
        for (int curStartLocation : startLocations) {
            curSum += distFromStart[curStartLocation][i];
        }

        if (curSum < min_num) {
            min_num = curSum;
            min_location = i;
        }
    }

    return min_location;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;
   
        int a, b, c;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;

            graph[a].push_back({ c, b });
            graph[b].push_back({ c, a });
        }

        cin >> K;
        int k;
        for (int i = 0; i < K; i++) {
            cin >> k;
            startLocations.push_back(k);
        }

        cout << solution() << '\n';

        for (int i = 1; i <= N; i++) graph[i].clear();
        startLocations.clear();
    }
}
