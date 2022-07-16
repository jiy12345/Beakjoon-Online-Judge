#include<iostream>
#include<queue>
using namespace std;

#define LEFT 0
#define RIGHT 1

int di[3]			= { 1, -1, 0 };
int dLeftOrRight[3]	= { 0, 0, 1 };

int N, k;
string gameMap[2];

bool bfs() {
	
	queue<vector<int>>bfs_queue;

	bfs_queue.push({ 0, 0, LEFT });
	while (!bfs_queue.empty()) {
		int cur_depth		= bfs_queue.front()[0];
		int cur_i			= bfs_queue.front()[1];
		int cur_leftOrRight = bfs_queue.front()[2];
		bfs_queue.pop();

		for (int i = 0; i < 3; i++) {
			int next_depth			= cur_depth + 1;
			int next_i				= cur_i + di[i];
			int next_leftOrRight	= (cur_leftOrRight + dLeftOrRight[i]) % 2;
			
			// 승리 조건
			if (next_i >= N) return true;
			
			if (next_i < 0 || next_i <= cur_depth || gameMap[next_leftOrRight][next_i] == '0') continue;
			gameMap[next_leftOrRight][next_i] = '0'; // 방문 표시
			bfs_queue.push({ next_depth, next_i, next_leftOrRight });

		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;
	di[2] = k;

	for (int i = 0; i < 2; i++)
		cin >> gameMap[i];

	cout << bfs();
}
