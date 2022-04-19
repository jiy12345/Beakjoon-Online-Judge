#include<iostream>
#include<cstring>
using namespace std;


/*
1. 문제 분석
- 변수
T: 테스트 케이스의 수
r: 학생의 수

 - 변수 제한 사항
n: 2 ~ 100,000

- 문제 상황
학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.

프로젝트 팀에 속하지 못한 학생들의 수를 나타내라

2. 풀이 계획
 인접 리스트 형태로 그래프를 저장한 뒤, 사이클을 이룰 경우 팀으로, 그렇지 않을 경우 팀에 속하지 않는 것으로 표현

 일단 사이클을 찾아야 하는 문제는 맞다.

 문제가 되는 부분은 무엇일까?

사이클 체크를 방문하지 않은 노드 중 이전 노드가 아닌 노드일 경우에 체크하고 있는데,

이렇게 할 경우 다른 경로에서 사이클을 가리켰을 경우를 체크하지 못한다.

그렇다면 어떻게 해야할까?

사이클이 완성된 경우 따로 표시해주는 것은 어떨까?
 => 사이클이 일단 완성되면 다른 사람과는 팀을 이룰수는 없으므로, 아예 방문하지 못하도록 하는 것이다.

일단

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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