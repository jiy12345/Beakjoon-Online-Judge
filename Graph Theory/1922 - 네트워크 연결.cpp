#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 컴퓨터의 수
M: 가능한 연결의 개수


- 변수 제한 사항
N: 1 ~ 1,000
M: 1 ~ 100,000

모든 컴퓨터가 연결되지 않는 경우는 없다.

- 문제 상황
 각 컴퓨터간 연결하는데 드는 비용이 주어졌을 때, 
 모든 컴퓨터를 연결하는데 필요한 최소 비용을 출력한다.

2. 풀이 계획

최소 스패닝 트리를 구할 때는 경로를 따로 지정할 필요가 없으므로, 우선 순위 큐에 넣어 간선을 하나씩 빼고,

union find 알고리즘으로 양 쪽 다 연결되어 있을 때는 무시하고 넘어간다!

3. 계획 검증
*/

#define MAX 1001

int V, E;
// C, A, B 순으로 저장
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> links;
int Parent[MAX];

int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x == y) return true;
	else return false;
}

int solution() {
	int answer = 0;

	for (int i = 1; i <= V; i++) {
		Parent[i] = i;
	}

	while (!links.empty()) {
		vector<int> cur_link(links.top());
		links.pop();
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// 가중치를 가장 앞에 놔 가중치 기준으로 정렬되도록 함
		links.push({ c, a, b });
	}

	cout << solution();
}