#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 10
// 0과 1은 사용중이므로 2 ~ 7번 사용
#define MAX_ISLAND 10

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int N, M;
int islandNum = 2;
// 가중치, 출발 섬, 도착 섬 순으로 저장
vector<vector<int>> possibleLinks;
int Parent[MAX_ISLAND];
int islandMap[MAX][MAX];

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

void bfs(int start_i, int start_j, int cur_num) {
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ start_i, start_j });
	islandMap[start_i][start_j] = cur_num;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j) == false) continue;

			if (islandMap[next_i][next_j] == 1) {
				islandMap[next_i][next_j] = cur_num;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}
}

void numberingIslands() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (islandMap[i][j] == 1) {
				bfs(i, j, islandNum);
				islandNum++;
			}
		}
	}
}

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

void getPossibleLocation(int start_i, int start_j) {
	int startIsland = islandMap[start_i][start_j];

	for (int i = 0; i < 4; i++) {
		int cur_i = start_i, cur_j = start_j, distance = 0;

		// 상하좌우 네 방향 중에서 한 방향으로 쭉 직진
		while (true) {
			cur_i += di[i];
			cur_j += dj[i];

			if (isInRange(cur_i, cur_j) == false || islandMap[cur_i][cur_j] == startIsland) break;
			if (!islandMap[cur_i][cur_j]) {
				distance++;
				continue;
			}
			if (islandMap[cur_i][cur_j]) {
				if (distance > 1) {
					possibleLinks.push_back({ distance, startIsland, islandMap[cur_i][cur_j] });
					break;
				}
				break;
			}
		}
	}
}

void getPossibleLinks() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 섬에 속하는 땅일 경우
			if (islandMap[i][j] != 0) getPossibleLocation(i, j);
		}
	}

}

int kruskal() {
	int cnt = 1; // 총 몇개의 섬을 연결했는가?
	int answer = 0;

	for (int i = 0; i < N; i++) {
		Parent[i] = i;
	}


	for (vector<int> cur_link : possibleLinks) {
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			cnt++;
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
		}
	}

	return (cnt == islandNum - 2) ? answer : -1;
}

int solution() {
	numberingIslands();

	getPossibleLinks();

	sort(possibleLinks.begin(), possibleLinks.end());

	return kruskal();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> islandMap[i][j];
		}
	}

	cout << solution();
}