#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
 V: ������ ����
 E: ������ ����
 W: ������ ����ġ(���)
 K: ���� ������ ��ȣ

- ���� ���� ����
 V: 1~20,000
 E: 1~300,000
 W: 1~10

 ���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ����

- ���� ��Ȳ
 ������ ������ ���� ���¿� ���� ������ �־��� ��, 


2. Ǯ�� ��ȹ
 �������� ���ͽ�Ʈ�� �����̴�!

 �׷��� ������ ������ 20000���̹Ƿ�, ������ ������ 2���� �迭�� ����� 20,000*20,000*4=1.6�Ⱑ�� �Ǿ� �ſ� Ŀ���� �ȴ�.

 ���� linked 

*/

#define INF 200000;

int V, E;


vector<pair<int, int>> V_state[20001];

int min_distance[20001];

void solution(int startNode) {
	// �ڽ� ������ �̵��� 0
	min_distance[startNode] = 0;
	
	// top�� �ּҰ����� �����ϴ� priority queue(min heap)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push(make_pair(0, startNode));

	while (!pq.empty()) {
		// ���� �������� �ּ� �Ÿ�
		int cur_distance = pq.top().first;
		// ���� �湮�� ���
		int cur_node = pq.top().second;

		pq.pop();

		// �ִܰŸ��� �ƴ� ��� ��ŵ
		if (min_distance[cur_node] < cur_distance) continue;
		for (int i = 0;i < V_state[cur_node].size();i++) {
			// ���� ��带 ���ļ� ���� ���� ���� ���
			int next_distance = cur_distance + V_state[cur_node][i].first;
			// ���� �湮�� ���
			int next_node = V_state[cur_node][i].second;
			
			if (next_distance < min_distance[next_node]) {
				min_distance[next_node] = next_distance;
				pq.push(make_pair(next_distance, next_node ));
			}
		}
	}

	for (int i = 1;i <= V;i++) {
		if (min_distance[i] == 200000) {
			cout << "INF\n";
		}
		else {
			cout << min_distance[i] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startNode;

	cin >> V >> E;

	cin >> startNode;

	for (int i = 0;i < E ;i++) {
		int node1;
		int node2;
		int weight;

		cin >> node1 >> node2 >> weight;

		V_state[node1].push_back({ weight, node2 });
	}

	for (int i = 1; i <= V;i++) {
		min_distance[i] = INF;
	}

	solution(startNode);
}