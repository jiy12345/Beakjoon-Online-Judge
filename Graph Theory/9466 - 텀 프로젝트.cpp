#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100001

int T, n, numIsInTeam;
int graph[MAX];
int prevNode[MAX];

bool isVisited[MAX];
bool searchCompleted[MAX];

void findTeam(int nodeNum) {

	isVisited[nodeNum] = true;

	int next = graph[nodeNum];

	if (!isVisited[next]) findTeam(next);

	//이미 방문했지만 탐색이 끝난 노드가 아니라면 사이클
	else if (!searchCompleted[next]) {
		// 팀에 포함되는 인원 세기
		for (int i = next; i != nodeNum; i = graph[i])
			numIsInTeam++;
		numIsInTeam++;
	}

	// 현재 노드로부터 가는 모든 경로 탐색 완료
	searchCompleted[nodeNum] = true;
}

int solution() {
	for (int i = 1; i <= n; i++) {
		if (isVisited[i] == false) {
			findTeam(i);
		}
	}

	return n - numIsInTeam;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		numIsInTeam = 0;
		memset(isVisited, false, sizeof(isVisited));
		memset(searchCompleted, false, sizeof(searchCompleted));
		cin >> n;

		for (int student = 1; student <= n; student++) {
			cin >> graph[student];
		}

		cout << solution() << '\n';
	}

	return 0;
}
