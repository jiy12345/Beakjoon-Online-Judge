#include<iostream>
#include<vector>
using namespace std;


/*
1. 문제 분석
- 변수
n: 전체 사람의 수
m: 부모 자식 관계의 수
x, y: x가 y의 부모

 - 변수 제한 사항
n: 1 ~ 100

각 사람의 부모는 최대 한 명만 주어진다.
 => 다른 경로가 나올 수 없다.
 => 따라서 따로 백트래킹을 진행할 필요 없이 탐색을 진행하면 된다.

- 문제 상황
 입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다.

 두 사람이 친척 관계가 아니라면 -1을 출력하한다.

2. 풀이 계획


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int n, m;
vector<int> graph[100001];
bool isVisited[100001];
int parentNode[100001];

int dfs(int cur_node, int cur_dist, int end_node) {
	if (cur_node == end_node) return cur_dist;

	for (int i = 0; i < graph[cur_node].size(); i++) {
		int next_node = graph[cur_node][i];
		if (isVisited[next_node] == false) {
			isVisited[next_node] = true;
			int result = dfs(next_node, cur_dist + 1, end_node);
			if (result != -1) return result;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int start_node, end_node;

	cin >> n;

	cin >> start_node >> end_node;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		graph[parent].push_back(child);
		graph[child].push_back(parent);
	}

	cout << dfs(start_node, 0, end_node);

	return 0;
}