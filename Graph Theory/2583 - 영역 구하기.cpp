#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
M: 모눈종이의 세로 길이
N: 모눈종이의 가로 길이
K: 직사각형의 개수

- 변수 제한 사항
M, N, K: 1~100  


- 문제 상황
주어진 영상이 모두 0으로 되어 있다면 압축 결과를 0으로, 모두 1로 되어 있다면 압축 결과는 1로 압축할 수 있다고 하며,
0과 1이 섞여 있다면 쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현해야 한다고 할 때,

주어진 영상을 압축한 결과를 출력하는 영상을 출력하는 프로그램을 작성하라!

2. 풀이 계획
 재귀적으로 호출을 진행하여, 각 위치를 압축한 내용을 각 위치에서 출력하면 될 듯 하다!

 => 이때, 넘겨줘야할 매개변수는, 시작좌표와 현재 사이즈정도 일 듯 하다!
*/

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