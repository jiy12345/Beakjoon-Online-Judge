#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: �׷��ͱ��� ����
M: ���ֱ��� ����
d: ���ֱ��� ����

 - ���� ���� ����

 N: 2 ~ 4,000
 M: 1 ~ 100,000

 d: 1 ~ 100,000

 ���ֱ��� �����
 � �� �׷��ͱ� ���̿� �� �� �̻��� ���ֱ��� ���ִ� ���� ����!
 �޺� ����� �޺� ����� ��� 1������ ���

- ���� ��Ȳ

 ���� ������ ���� �ܰ迡 ���� ������

 ũ�Ⱑ ���� ���� �� �׷��� ����. �� ����, ���� ������ ���� ���� X, ū ���� Y��� ���Ѵ�. �� ����, X�� �ִ� ���� ������ X+X����, Y�� �ִ� ���� ������ Y-X���� �����.

2. Ǯ�� ��ȹ
 ������ ���� ����, ���� ���� ������ ���� �� �ִ��� ���θ� ������ ���̹Ƿ�,

 ��� ������ ���θ� �Ǵ��ϴ� ���� ���� �߿��ϴ�.

 �ϴ� �Ʒ��� �� ���� �� �׷��� ������ 0�� �ȴٸ� �� �̻� ������ �� �����Ƿ� �ű⼭ ������ �Ѵ�.

 ���� ���� �� ���� ���� ū ���� �� �� ���� ���� 500, 499�� �� �̹Ƿ�, 1000�̻����δ� ���� �� �� ����.

 ���� 1000 ũ���� 3���� �迭�� �湮 ǥ�ø� �����ϰ�, ã���� 1, ��ã�� �����ϸ� 0�� ����ϸ� �� �� �ϴ�.

 �׷��� �ణ �����Ǵ� ���� �ð����⵵�� ���� ���⵵ ����?

 ������ �ڼ��� ����, �ѹ� ������ ���� �� X�� ���ϰ� X�� �� ���̹Ƿ� ��ü�� ��(A + B + C)�� �ٲ��� �ʴ� ���� �� �� �ִ�.

 �� ���� ������ 3���� �� �׷��� ��Ÿ�� �� �ִ�!


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

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

        // ���� ��忡�� ���� �������� ���� �ӵ��� �ݴ�� ���� ������ �Ա� ������
        // ���� �ӵ��� �ݴ��� �ӵ��� ��
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
