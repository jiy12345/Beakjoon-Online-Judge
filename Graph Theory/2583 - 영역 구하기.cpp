#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K;

int grid_paper[100][100];

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

inline bool is_in_scope(int i, int j) {
	if (0 <= i && i < M && 0 <= j && j < N) {
		return true;
	}
	else {
		return false;
	}
}

int bfs(int start_i, int start_j) {
	int size = 1;

	queue<pair<int, int>> bfs_queue;

	bfs_queue.push({start_i, start_j});
	grid_paper[start_i][start_j] = 1;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();

		for (int i = 0;i < 4;i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (is_in_scope(next_i, next_j) && grid_paper[next_i][next_j] == 0){ 
				size++;
				grid_paper[next_i][next_j] = 1;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}

	return size;
}

void solution() {
	vector<int> area_size;

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (grid_paper[i][j] == 0) {
				area_size.push_back(bfs(i, j));
				for (int i = 0;i < M;i++) {
					for (int j = 0; j < N;j++) {
						cout << grid_paper[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
		}
	}

	sort(area_size.begin(), area_size.end());

	cout << area_size.size() << '\n';

	for (int i = 0;i < area_size.size();i++) {
		cout << area_size[i] << " ";
	}
}

inline void fill_grid_paper(int LBi, int LBj, int RTi, int RTj) {
	for (int i = LBi;i < RTi;i++) {
		for (int j = LBj; j < RTj;j++) {
			grid_paper[j][i] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	int LBi ,LBj, RTi, RTj;

	for (int i = 0;i < K;i++) {
		cin >> LBi >> LBj >> RTi >> RTj;
		fill_grid_paper(LBi, LBj, RTi, RTj);

		for (int i = 0;i < M;i++) {
			for (int j = 0; j < N;j++) {
				cout << grid_paper[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	solution();
}
