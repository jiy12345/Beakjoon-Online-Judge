#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int N, M;
bool isVisited[1000][1000];
string map[1000];
pair<int, int> blankArea[1000][1000]; // 각 연결된 빈칸의 면적 기록
int blankAreaNum;

inline bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

void areaCalc(int i, int j) {
	queue<pair<int, int>> bfs_queue;
	vector<pair<int, int>> includedArea; // 현재 영역에 포함된 위치정보 담기위한 벡터

	bfs_queue.push({i, j});
	isVisited[i][j] = true;

	int curArea = 0; // 현재 연결된 빈칸들의 면적 계산

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();

		curArea++;
		includedArea.push_back({ cur_i, cur_j });

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			if (isInRange(next_i, next_j) && map[next_i][next_j] == '0' && isVisited[next_i][next_j] == false) {
				isVisited[next_i][next_j] = true;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}

	// 같은 영역에 속한 범위에 넓이와 번호 입력해주기
	for (pair<int, int> location : includedArea) {
		blankArea[location.first][location.second] = { curArea, blankAreaNum };
	}

	blankAreaNum++;
}

void solution() {
	// 각 인접한 빈칸들의 넓이 계산
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (isVisited[i][j] == false && map[i][j] == '0')
				areaCalc(i, j);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '1') {
				int curArea = 1;
				vector<int> includedArea;
				for (int k = 0; k <4; k++) {

					int next_i = i + di[k];
					int next_j = j + dj[k];

					int area = blankArea[next_i][next_j].first;
					int areaNum = blankArea[next_i][next_j].second;

					// 맵의 범위 내이고,
					// 아직 포함되지 않은 영역이며, 
					// 벽이 아닐 때만 포함
					if (isInRange(next_i, next_j) 
						&& find(includedArea.begin(), includedArea.end(), areaNum) == includedArea.end()
						&& area != 0
						) {
						curArea += area;
						// 이미 사용한 공간이라는 기록 남기기
						includedArea.push_back(areaNum);
					}
				}
				curArea %= 10;

				map[i][j] = curArea + 48;
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	solution();

	for (int i = 0; i < N; i++)
		cout << map[i] << '\n';

	return 0;
}
