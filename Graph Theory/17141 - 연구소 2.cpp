#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 50
#define MAX_ROUTE 2500

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int N, M;
int grid[MAX][MAX];
vector<vector<int>> combinations;

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

int bfs(vector<pair<int, int>> virus_loc) {
	int answer = MAX_ROUTE;
	queue<vector<int>> bfs_queue;

	vector<vector<bool>> isVisited(N, vector<bool>(N, false));
	vector<vector<int>> Map(N, vector<int>(N, -1));

	// bfs 큐에 정해진 바이러스 위치 집어넣기
	// 바이러스의 위치 표시하기(방문 표시를 위하여
	for (pair<int, int> virus : virus_loc) {
		bfs_queue.push({ 0, virus.first, virus.second });
		grid[virus.first][virus.second] = 2;
	}

	// 빈칸이 아닌 위치들 방문 표시하기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] != 0) isVisited[i][j] = true;

	while (true) {
		int cur_depth = bfs_queue.front()[0];
		int cur_i = bfs_queue.front()[1];
		int cur_j = bfs_queue.front()[2];
		bfs_queue.pop();
		Map[cur_i][cur_j] = cur_depth;

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j) == false) continue;

			if (isVisited[next_i][next_j] == false && grid[next_i][next_j] == 0) {
				isVisited[next_i][next_j] = true;
				bfs_queue.push({ cur_depth + 1, next_i, next_j });
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("%3d", Map[i][j]);
			cout << endl;
		}
		cout << endl;


		if (bfs_queue.empty()) {
			answer = cur_depth;
			break;
		}
	}

	// 바이러스 표시했던 것들 다시 풀어주기
	for (pair<int, int> virus : virus_loc) {
		grid[virus.first][virus.second] = 0;
	}

	// 다 감염시키지 못했을 경우
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (isVisited[i][j] == false) return MAX_ROUTE;
	return answer;
}

void getCombinations(int index, int K, int N, vector<int> subSequence) {
	int curSize = subSequence.size();
	if (curSize == K) {
		combinations.push_back(subSequence);
		return;
	}

	for (int i = index; i < N; i++) {
		subSequence.push_back(i);
		getCombinations(i + 1, K, N, subSequence);
		subSequence.pop_back();
	}
}


int solution(vector<pair<int, int>> possible_loc) {
	int answer = MAX_ROUTE;

	// 가능한 조합 구하기
	vector<int> subSequence;
	getCombinations(0, M, possible_loc.size(), subSequence);

	// 해당 조합을 이용한 bfs 진행
	for (vector<int> cur_combination:combinations) {
		cout << "cur_combination: ";
		vector<pair<int, int>> virus_loc;
		for (int i : cur_combination) {
			cout << i << " ";
			virus_loc.push_back(possible_loc[i]);
		}
		cout << endl;

		int cur_min_route = bfs(virus_loc);

		cout << "cur_min_route: " << cur_min_route << endl;

		answer = min(answer, cur_min_route);
	}

	return (answer == MAX_ROUTE) ? -1 : answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	vector<pair<int, int>> possible_loc;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 2) {
				possible_loc.push_back({ i, j });
				grid[i][j] = 0;
			}
		}

	cout << solution(possible_loc);
}
