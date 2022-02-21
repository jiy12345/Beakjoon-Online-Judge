#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
S: 이모티콘의 개수

- 변수 제한 사항
S: 2 ~ 1,000

- 문제 상황
 1개의 이모티콘이 입력되어 있을 때, 다음과 같은 3가지 연산을 사용하여 이모티콘을 S개 만드려고 한다.

 1. 화면에 있는 이모티콘을 모모두 복사하여 클립보드에 저장
 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
 3. 화면에 있는 이모티콘 중 하나 삭제

2. 풀이 계획

전형적인 BFS 문제이다

아직 방문하지 않은(큐에 푸시되지 않은) 노드이며
3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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

		//cout << "cur_num: " << cur_num << ", ";
		//cout << "cur_clipBoard: " << cur_clipBoard << ", ";
		//cout << "cur_depth: " << cur_depth << endl;

		//cout << "cur_num: " << cur_num << ", ";
		//cout << "bfs_queue.size(): " << bfs_queue.size() << endl;

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