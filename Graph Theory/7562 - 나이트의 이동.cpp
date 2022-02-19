#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
