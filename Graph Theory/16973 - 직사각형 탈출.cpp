#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N, M: �������� ����, ���� ����
H, W: ���簢���� ũ��

- ���� ���� ����
2 �� N, M �� 1,000
1 �� H �� N
1 �� W �� M
1 �� Sr �� N-H+1
1 �� Sc �� M-W+1
1 �� Fr �� N-H+1
1 �� Fc �� M-W+1
�Է����� �־��� ���簢���� �������� ����� �ʰ�, ���簢���� ���� �ִ� ĭ���� ���� ����.

- ���� ��Ȳ
 ���簢���� ���� ��ġ, ��ǥ ��ġ, �������� ���°� �־����� ��,

 ���簢���� �ּ� �̵� Ƚ���� ���Ͽ���.

 �̵��� �� ���� ��쿡�� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ
 �� ��ġ���� �ѹ��� ����ϸ� �� �� �ϴ�!


3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/

#define MAX 1001

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int N, M;
int H, W;
int S_r, S_c, F_r, F_c;
int grid[MAX][MAX];

int isInRange(int i, int j) {
	// �� ��� �� ���ϴ� ��ǥ ���� üũ
	return 1 <= i && i + H - 1 <= N && 1 <= j && j + W - 1 <= M;
}

int bfs() {
	int answer = -1;

	queue<vector<int>>bfs_queue;
	vector<vector<bool>> isVisited(N + 1, vector<bool>(M + 1, false));

	bfs_queue.push({ 0, S_r, S_c });
	isVisited[S_r][S_c] == true;

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front()[0];
		int cur_i = bfs_queue.front()[1];
		int cur_j = bfs_queue.front()[2];
		bfs_queue.pop();

		if (cur_i == F_r && cur_j == F_c) {
			answer = cur_depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_depth = cur_depth + 1;
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			
			if (isInRange(next_i, next_j) == false || 
				isVisited[next_i][next_j] == true || 
				grid[next_i][next_j] == 1) continue;

			bfs_queue.push({ next_depth, next_i, next_j });
			isVisited[next_i][next_j] = true;
		}
	}

	return answer;
}

int solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (grid[i][j] == 1) {
				for (int y = i; y >= i - H + 1 && y >= 1; y--) {
					for (int x = j; x >= j - W + 1 && x >= 1; x--) {
						grid[y][x] = 1;
					}
				}
			}
		}
	}

	return bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) 
			cin >> grid[i][j];

	cin >> H >> W >> S_r >> S_c >> F_r >> F_c;

	cout << solution();
}