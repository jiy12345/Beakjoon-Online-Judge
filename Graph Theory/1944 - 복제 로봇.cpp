#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 미로의 세로, 가로 길이
M: 열쇠의 개수

- 변수 제한 사항
N: 4 ~ 50
M: 1 ~ 250

- 미로 관련
1: 미로의 벽
0: 다닐 수 있는 길
S: 로봇이 출발하는 위치
K: 열쇠의 위치

미로의 모든 테두리는 벽으로 이루어진 입력만 주어진다.

- 문제 상황
 찾으려는 열쇠의 개수, 미로의 상태가 주어졌을 때,
 로봇이 움직인 횟수의 총합을 구하는 프로그램을 작성하라.
 모든 열쇠를 찾는 것이 불가능한 경우 회

2. 풀이 계획

1. 출발 위치부터 BFS를 진행하며, 처음 열쇠를 찾으면 종료한다.
2. 열쇠를 찾은 위치로부터 다시 BFS를 진행하며, 열쇠를 찾으면 종료한다.
3. 정해진 개수의 열쇠를 모두 찾았으면 총 이동 거리를 출력하며, 그렇지 않고 찾지 못하고 종료되었다면 -1을 출력한다.

3. 계획 검증
 알고리즘상의 문제가 있다.

 최소 스패닝 트리 문제가 아닌줄 알았는데 최소 스패닝 트리 문제가 맞았다.

 로봇의 복제가 가능하기 때문에 중간에 여러 경로로 나누어져 여러 곳으로 가는 것도 가능해야 하기 때문에

 그냥 각 위치에서의 가장 가까운 키(혹은 출발점)을 찾아놓고 크루스칼 알고리즘을 돌리면 될 듯 하다.

*/

#define MAX 50
// 출발점을 포함한 최대 키 개수 251개 이므로
#define MAX_KEY 252

int N, M;
int maze[MAX][MAX];
bool isVisited[MAX][MAX];
int Parent[MAX_KEY];
vector<vector<int>> keyLocations;
vector<vector<int>> possibleLinks;

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y) {
	return findParent(x) == findParent(y);
}

int kruskal() {
	int answer = 0;
	int cnt = 1; // 합쳐진 노드의 수를 셀 변수

	for (int i = 0; i <= M; i++) {
		Parent[i] = i;
	}

	int size = possibleLinks.size();

	for (int i = 0; i < size; i++) {
		vector<int> cur_link(possibleLinks[i]);
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);

			answer += cur_link[0];
			cnt++;
			if (cnt == M + 1) return answer;
		}
	}

	return -1;
}

// bfs를 통해 각 키 혹은 출발점에서 다른 키 혹은 출발점으로의 경로 계산하는 함수
// 경로가 있을 경우 true 반환
// 그렇지 않을 경우 false 반환
void findRoute(pair<int, int> curLocation, int startNum) {
	int start_i = curLocation.first;
	int start_j = curLocation.second;

	queue<vector<int>>bfs_queue;

	bfs_queue.push({ 0, start_i, start_j });
	isVisited[start_i][start_j] = true;

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front()[0];
		int cur_i = bfs_queue.front()[1];
		int cur_j = bfs_queue.front()[2];
		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isVisited[next_i][next_j] == false && maze[next_i][next_j] != 1) {
				bfs_queue.push({ cur_depth + 1, next_i, next_j });
				isVisited[next_i][next_j] = true;

				if (maze[next_i][next_j] != 0) {
					// 각 키에서 출발점 혹은 또다른 키로의 경로 가능한 경로에 추가
					possibleLinks.push_back({ cur_depth + 1, startNum, maze[next_i][next_j] });
				}
			}
		}
	}
}

int solution() {
	for (int i = 0; i <= M; i++) {
		// 각 위치에서의 가능한 경로들을 모두 구하기
		findRoute({ keyLocations[i][0], keyLocations[i][1] }, keyLocations[i][2]);

		memset(isVisited, false, sizeof(isVisited));
	}

	sort(possibleLinks.begin(), possibleLinks.end());

	return kruskal();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int location_num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char curLocation;
			cin >> curLocation;

			// 각 키와 출발점에 번호 매기기
			if (curLocation == 'S'|| curLocation == 'K') {
				maze[i][j] = location_num;
				keyLocations.push_back({ i, j, location_num++ });
			}
			else {
				maze[i][j] = curLocation - '0';
			}
		}
	}

	cout << solution();
}