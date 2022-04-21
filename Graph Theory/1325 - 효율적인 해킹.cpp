#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


/*
1. 문제 분석
- 변수
N: 컴퓨터의 개수
M: 간선의 개수

 - 변수 제한 사항
N: 1 ~ 10,000
M: 1 ~ 100,000

- 문제 상황
 A가 B를 신뢰하는 경우 B를 해킹하면 A도 해킹할 수 있다.

2. 풀이 계획



3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define MAX 10001

int N, M;
vector<int> graph[MAX];
int numHack[MAX];
bool isVisited[MAX];

int dfs(int cur_node) {
	isVisited[cur_node] = true;

	int cur_numHack = 1; // 기본적으로 현재 컴퓨터는 항상 해킹 되므로

	for (int next_node : graph[cur_node])
		if (isVisited[next_node] == false) 
			cur_numHack += dfs(next_node);

	return cur_numHack;
}

void solution() {
	int maxNum = 0;

	// 모든 노드에 대해 탐색하며 각 컴퓨터를 해킹했을 때 해킹할 수 있는 컴퓨터의 수 찾고,
	// 그 최대값 구하기
	for (int i = 1; i <= N; i++) {
		memset(isVisited, false, sizeof(isVisited));
		numHack[i] = dfs(i);
		maxNum = max(maxNum, numHack[i]);
	}

	for (int i = 1; i <= N; i++) {
		// cout << numHack[i] << " ";
		if (numHack[i] == maxNum) cout << i << " ";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int root = 0;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}

	solution();

	return 0;
}