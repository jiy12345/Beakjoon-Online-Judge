#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
I: 체스판의 한변의 길이

- 변수 제한 사항
I: 4 ~ 300

- 문제 상황
 나이트의 현재 위치와 나이트가 가야할 위치가 주어질 때, 나이트가 최소 몇번만에 이동할 수 있는지를 구하여라

2. 풀이 계획

전형적인 BFS 문제이다

아직 방문하지 않은(큐에 푸시되지 않은) 노드이며 체스판 범위 내의 노드일 때만 진행

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int di[8] = { +2, +2, +1, +1, -1, -1, -2, -2 };
int dj[8] = { -1, +1, -2, +2, -2, +2, -1, +1 };

inline bool isInRange(int i, int j, int I) {
	return (0 <= i && i < I && 0 <= j && j < I);
}

int solution(pair<int, int> startNode, pair<int, int> destNode, int I) {
	vector<vector<bool>>isVisited(I, vector <bool>(I));

	queue<vector<int>>bfs_queue;

	bfs_queue.push({ startNode.first, startNode.second, 0 });

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		bfs_queue.pop();

		//cout << "(cur_i, cur_j): " << "(" << cur_i << ", " << cur_j << ")\n";

		if (cur_i == destNode.first && cur_j == destNode.second) {
			return cur_depth;
		}

		for (int i = 0; i < 8; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if(isInRange(next_i, next_j, I) && isVisited[next_i][next_j] == false) {
				isVisited[next_i][next_j] = true;

				bfs_queue.push({ next_i, next_j, cur_depth + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		pair<int, int>startNode;
		pair<int, int>destNode;
		int I;

		cin >> I;
		cin >> startNode.first >> startNode.second;
		cin >> destNode.first >> destNode.second;

		cout << solution(startNode, destNode, I) << '\n';
	}

	return 0;
}