#include<iostream>
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

int V, E;
// C, A, B 순으로 저장
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> links;
int Parent[10001];

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
	int cnt = 0; // 방문한 노드의 수

	for (int i = 1; i <= V; i++)
	{
		Parent[i] = i;
	}

	while(!links.empty()) {
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
		int A, B, C;
		cin >> A >> B >> C;
		// 가중치를 가장 앞에 놔 가중치 기준으로 정렬되도록 함
		links.push({ C, A, B });
	}

	cout << solution();
}