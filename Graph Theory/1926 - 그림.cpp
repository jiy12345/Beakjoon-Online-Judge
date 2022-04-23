#include<iostream>
#include<queue>
using namespace std;


/*
1. 문제 분석
- 변수
n: 도화지의 세로 크기
m: 도화지의 가로 크기

 - 변수 제한 사항
n, m: 1 ~ 500

- 문제 상황

2. 풀이 계획
모든 방문하지 않은 위치에 대해 넓이 구해야 할듯

- 틀릴 수 있는 부분
 열의 번호? 왼쪽 노드들 부터 계산되므로 문제 없을 듯 하다.
 깊이?

2. 레벨의 너비를 구한다.
3. 너비의 최대값을 구한다.

루트 노드는 어떻게 찾아야 할까?


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define MAX 500

int n, m;
int drawingPaper[MAX][MAX];
bool isVisited[MAX][MAX];
int numOfPaintings;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int isInRange(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int bfs(int start_i, int start_j) {
	numOfPaintings++;

	int area = 0;

	queue<pair<int, int>> bfs_queue;

	isVisited[start_i][start_j] = true;
	bfs_queue.push({ start_i, start_j });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();
		area++;
		
		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (!isInRange(next_i, next_j) || isVisited[next_i][next_j]) continue;

			if (drawingPaper[next_i][next_j] == 1) {
				isVisited[next_i][next_j] = true;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}

	return area;
}

void solution() {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (drawingPaper[i][j] == 1 && isVisited[i][j] == false) answer = max(answer, bfs(i, j));
		}
	}

	cout << numOfPaintings << '\n';
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> drawingPaper[i][j];
		}
	}

	solution();

	return 0;
}