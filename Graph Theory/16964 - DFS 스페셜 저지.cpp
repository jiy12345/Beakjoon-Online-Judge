#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
