#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석

- 변수
w: 너비
h: 높이

- 변수 제한 사항
w, h: 0~50!

- 문제 상황
입력은 여러 개의 테스트 케이스로 이루어져 있으며, 각 테스트 케이스에서는 너비 w와 높이 h가 주어지고,

다른 정사각형과 가로, 세로, 또는 대각선으로 연결되어 있는 사각형의 모임을 하나의 섬이라고 할 때,

지도가 1은 땅, 0은 바다로 주어질 때, 섬의 개수를 구하여라

2. 풀이 계획
모든 1인 부분(땅)에 대해 BFS를 진행하며, 

3. 계획 검증


*/

int dx[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };


void bfs(int map[][52], pair<int, int> start_node) {
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(start_node);

	while (!bfs_queue.empty()) {
		pair<int, int> cur_node = bfs_queue.front();
		bfs_queue.pop();

		// 8 방향에 대해 모두 체크
		for (int i = 0;i < 8;i++) {
			int cur_x = cur_node.first + dx[i];
			int cur_y = cur_node.second + dy[i];

			// 이미 탐색한 노드 표시
			if (map[cur_x][cur_y] == 1) {
				map[cur_x][cur_y] = 0;
				bfs_queue.push({ cur_x, cur_y });
			}
		}
	}
}

int solution(int map[][52], int w, int h) {
	int cnt = 0;

	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			if (map[i][j] == 1) {
				cnt++;
				bfs(map, { i, j });
			}
		}
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int w, h;
	while (true) {
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		int map[52][52];

		for (int i = 1;i <= h;i++) {
			for (int j = 1;j <= w;j++) {
				cin >> map[i][j];
			}
		}

		cout << solution(map, w, h) << "\n";
	}

	return 0;
}