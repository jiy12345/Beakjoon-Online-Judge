#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 정점의 개수


- 변수 제한 사항
N: 2 ~ 100,000
트리 정보가 주어질 때는 1부터 N까지의 정점이 1번씩 등장한다.
시작 정점은 항상 1번 정점이다.

- 문제 상황
 트리의 정보가 주어지고, DFS의 방문 순서가 주어질 때,
 해당 방문 순서가 DFS로 가능한 방문 순서인지 체크하라

2. 풀이 계획

중요한 것은 각 시점에서 다음 위치가 나올수 있는 방문 순서인가이다.

따라서 탐색을 진행하면서 각 위치에서 갈 수 있는 위치들을 찾고, 끝까지 탐색할 때까지 계속해서 갈 수 있다면 


1. 1부터 탐색을 시작한다.
2. 현재 순서에 방문해야 하는 노드가 1과 연결되어 있는 노드인지 체크한다.
3. 위와 같이 연쇄적으로 방문하며, 리프 노드에 방문하였을 때는

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


int N;
vector<int> graph[100001];
vector<int> answer;

int visitOrder[100001];
bool isVisited[100001];
int cnt = 0;


bool comp(int a, int b) {
	return visitOrder[a] < visitOrder[b];
}


// dfs로 방문한 순서대로의 수열을 구해주는 함수
void dfs(int x) {
	answer.push_back(x);

	for (int node : graph[x]) {
		if (isVisited[node]) continue;
		isVisited[node] = true;
		dfs(node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		// 그래프의 노드 방문 순서 조정을 위해 각 노드가 방문되는 시점 저장
		visitOrder[input[i]] = i + 1;
	}

	// 첫 숫자가 1이 아닐 경우 틀림
	if (input[0] != 1) {
		cout << 0;
		return 0;
	}
	else {
		// 각 노드에 인접한 노드로의 방문 순서를 입력 순서에 맞춰 정렬
		for (int i = 1; i <= N; i++) {
			sort(graph[i].begin(), graph[i].end(), comp);
		}
		isVisited[1] = true;
		dfs(1);
	}

	if (answer == input) cout << 1;
	else cout << 0;

	return 0;
}