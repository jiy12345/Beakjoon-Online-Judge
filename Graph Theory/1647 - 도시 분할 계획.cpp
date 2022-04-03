#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 집의 개수
M: 집을 연결하는 길의 개수

A, B, C: A번 집과 B번 집을 연결하는 유지비가 C이다.

- 변수 제한 사항
N: 1 ~ 100,000
M: 1 ~ 1,000,000

C: 1 ~ 1,000

경로는 양방향이다.

- 문제 상황
 최소 스패닝 트리의 가중치를 구하여라

2. 풀이 계획

최소 스패닝 트리에서 가중치가 가장 높은 마지막 수 하나만 빼면 두 곳으로 나눈 최소 스패닝 트리를 구할 수 있다.

3. 계획 검증
*/

int V, E;
// C, A, B 순으로 저장
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> links;
int Parent[100001];

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
	int lastNum = 0; // 방문한 노드의 수

	for (int i = 1; i <= V; i++)
	{
		Parent[i] = i;
	}

	while (!links.empty()) {
		vector<int> cur_link(links.top());
		links.pop();
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
			lastNum = cur_link[0];
		}
	}

	return answer - lastNum;
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