#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ��(���)�� ����
M: ����� ����
K: ���ӿ� �����ϴ� ģ���� ��

T: �׽�Ʈ ���̽��� ����


- ���� ���� ����
N: 2 ~ 100
M: ~ 6,000
K: 0 ~ N

����� ������ ������ ���
����� ���̴� �ڿ���
�� ���� �����ϴ� �����δ� �ݵ�� �ϳ��� ����
� �濡�� �ٸ� ������ ��� ��θ� �̿��ؼ� �� �� ���� ���� �������� �ʴ´�.
���� ��� ��ο� ���� ������ �ߺ��Ǿ� �־����� �ʴ´�.

- ���� ��Ȳ
 �� �׽�Ʈ ���̽��� �־��� ��� ������ �������� ������ �� �ִ� ���� ª�� �ð��� ���϶�

 ���� �������� ������ �� ���� ��� Poor KCM�� ����϶�.


2. Ǯ�� ��ȹ
 ���ͽ�Ʈ�� �˰����� ���� ����ؼ� �ּ� �ð��� ����ϵ�, �� �ܰ迡�� ����� �ʰ��Ǵ� ��δ� �������� �ʵ��� �Ѵ�!

3. ��ȹ ����
*/

#define MAX 101
#define INF 6000 * 1000

// �ʿ��� ���� ����
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

        // ���� ������� �� ���� �ð� ���� �̹� �湮�ߴٸ� Ž�� X
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

    // ��� �������� ���� �ݺ�
    for (int i = 1; i <= N; i++) {
        int curSum = 0;

        // ��� ����������� �Ÿ� ���
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
