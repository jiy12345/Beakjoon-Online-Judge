#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 그루터기의 개수
M: 오솔길의 개수
d: 오솔길의 길이

 - 변수 제한 사항

 N: 2 ~ 4,000
 M: 1 ~ 100,000

 d: 1 ~ 100,000

 오솔길은 양방향
 어떤 두 그루터기 사이에 두 개 이상의 오솔길이 나있는 경우는 없다!
 달빛 여우와 달빛 늑대는 모두 1번에서 출발

- 문제 상황

 돌을 다음과 같은 단계에 따라 움직여

 크기가 같지 않은 두 그룹을 고른다. 그 다음, 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y라고 정한다. 그 다음, X에 있는 돌의 개수를 X+X개로, Y에 있는 돌의 개수를 Y-X개로 만든다.

2. 풀이 계획
 제한이 딱히 없고, 돌을 같은 개수로 만들 수 있는지 여부만 따지는 것이므로,

 어떻게 끝날지 여부를 판단하는 것이 가장 중요하다.

 일단 아래로 갈 때는 한 그룹의 개수가 0이 된다면 더 이상 움직일 수 없으므로 거기서 끝내야 한다.

 또한 위로 갈 때는 가장 큰 수가 될 수 있을 때가 500, 499일 떄 이므로, 1000이상으로는 절대 갈 수 없다.

 따라서 1000 크기의 3차원 배열에 방문 표시를 진행하고, 찾으면 1, 못찾고 종료하면 0을 출력하면 될 듯 하다.

 그런데 약간 걱정되는 것은 시간복잡도와 공간 복잡도 정도?

 연산을 자세히 보면, 한번 연산을 했을 때 X를 더하고 X를 뺀 것이므로 전체의 합(A + B + C)는 바뀌지 않는 것을 알 수 있다.

 두 수만 가지고도 3개의 돌 그룹을 나타낼 수 있다!


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define INF 987654321

#define MAX 4001
#define FAST 1
#define SLOW 0

int N, M;
vector<pair<int, int>> nodes[MAX];
int fox_distanceFromStart[4001];
int wolf_distanceFromStart[2][4001];

void fox_dijkstra() {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra_queue;
    dijkstra_queue.push({ 0, 1 });
    fox_distanceFromStart[1] = 0;

    while (!dijkstra_queue.empty()) {
        int cur_node = dijkstra_queue.top().second;
        int cur_cost = dijkstra_queue.top().first;
        dijkstra_queue.pop();

        if (fox_distanceFromStart[cur_node] < cur_cost) continue;

        for (int i = 0; i < nodes[cur_node].size(); i++) {
            int next_node = nodes[cur_node][i].first;
            int next_cost = cur_cost + nodes[cur_node][i].second;

            if (fox_distanceFromStart[next_node] > next_cost) {
                fox_distanceFromStart[next_node] = next_cost;
                dijkstra_queue.push({ next_cost, next_node });
            }
        }
    }
}


void wolf_dijkstra() {

    // dist, node, state
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> dijkstra_queue; 
    dijkstra_queue.push({ 0, 1, 1 });

    while (!dijkstra_queue.empty()) {
        int cur_cost = dijkstra_queue.top()[0];
        int cur_node = dijkstra_queue.top()[1];
        int cur_speed = dijkstra_queue.top()[2];
        dijkstra_queue.pop();

        // 이전 노드에서 현재 노드까지는 현재 속도의 반대로 다음 노드까지 왔기 때문에
        // 현재 속도와 반대의 속도로 비교
        if (wolf_distanceFromStart[(cur_speed + 1) % 2][cur_node] < cur_cost) continue;

        for (int i = 0; i < nodes[cur_node].size(); i++) {
            if (cur_speed == FAST) {
                int next_node = nodes[cur_node][i].first;
                int next_cost = cur_cost + nodes[cur_node][i].second / 2;

                if (wolf_distanceFromStart[1][next_node] > next_cost) {
                    wolf_distanceFromStart[1][next_node] = next_cost;
                    dijkstra_queue.push({ next_cost, next_node, SLOW });
                }
            }
            else if (cur_speed == SLOW) {
                int next_node = nodes[cur_node][i].first;
                int next_cost = cur_cost + nodes[cur_node][i].second * 2;

                if (wolf_distanceFromStart[0][next_node] > next_cost) {
                    wolf_distanceFromStart[0][next_node] = next_cost;
                    dijkstra_queue.push({ next_cost, next_node, FAST });
                }
            }
        }
    }
}

int solution() {
    for (int i = 1; i <= N; i++) {
        fox_distanceFromStart[i] = INF;
        wolf_distanceFromStart[0][i] = INF;
        wolf_distanceFromStart[1][i] = INF;
    }

	fox_dijkstra();
	wolf_dijkstra();

	int answer = 0;

	for (int i = 2; i <= N; i++) {
		if (fox_distanceFromStart[i] < min(wolf_distanceFromStart[0][i], wolf_distanceFromStart[1][i])) answer++;
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		nodes[a].push_back({ b, d * 2 });
		nodes[b].push_back({ a, d * 2 });
	}

	cout << solution();

	return 0;
}
