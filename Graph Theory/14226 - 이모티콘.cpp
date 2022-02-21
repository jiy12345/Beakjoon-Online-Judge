#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1001

bool isVisited[MAX][MAX];

int solution(int S) {
	queue<vector<int>>bfs_queue;

	int timeSpent = -1;

	// 현재 이모티콘의 개수 / 클립보드에 복사된 이모티콘의 수 / 현재 걸린 시간
	bfs_queue.push({1, 0, 0});
	isVisited[1][0] = true;


	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front()[0];
		int cur_clipBoard = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		bfs_queue.pop();

		if (cur_num == S) {
			timeSpent = cur_depth;
			break;
		}

		// 1. 클립보드에 저장
		if (isVisited[cur_num][cur_num] == false) {
			isVisited[cur_num][cur_num] = true;
			bfs_queue.push({ cur_num, cur_num, cur_depth + 1 });
		}

		// 2. 클립보드에 있는 내용 붙여넣기
		int next_num = cur_num + cur_clipBoard;
		if (next_num < MAX && isVisited[next_num][cur_clipBoard] == false && cur_clipBoard != 0) {
			isVisited[next_num][cur_clipBoard] = true;
			bfs_queue.push({ next_num, cur_clipBoard, cur_depth + 1 });
		}

		// 3. 화면에 있는 이모티콘 삭제
		next_num = cur_num - 1;
		if (next_num >= 0 && isVisited[next_num][cur_clipBoard] == false) {
			isVisited[next_num][cur_clipBoard] = true;
			bfs_queue.push({ next_num, cur_clipBoard, cur_depth + 1 });
		}
	}

	return timeSpent;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int S;

	cin >> S;

	cout << solution(S);

	return 0;
}
