#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

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
