#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N, M: ����� ����, ���� ����
K: ���� �μ� �� �ִ� Ƚ��

 - ���� ���� ����
N, M: 1 ~ 1,000
K: 1 ~ 10

(1, 1)�� (N, M)�� �׻� �� �����̴�!

- ���� ��Ȳ
 ���� �ִ� K������ �μ� �� �ִٰ� �� ��, (1, 1) ��ġ���� N, M��ġ�� �̵��ϴ� �ִ� �Ÿ��� ����϶�

2. Ǯ�� ��ȹ
 �� ��ġ���� �湮 ǥ�ø� �����ϵ�, �湮 ǥ�ø� �μ� ���� ���ڷ� �����Ͽ�, ���ڰ� �� ���� ���� ���� �湮�� �� �ֵ��� �ϸ� �� �� �ϴ�.

 ���� ��ġ�� �������� �� ���� �μ� Ƚ���� �� ���ٸ� ������ �ʿ䰡 ������,
 ���� �μ� Ƚ���� �� ���ٸ� ���� ��ο� ������ ��ĥ �� �����Ƿ� ������ �־���Ѵ�.
 �� ��ġ������ ���� �μ� Ƚ���� ����ϰ�, ���� �� �� ��θ� ���ƿԴ��� �μ� ���� ������ ���ٸ� ������ �ִ� ������ �ϸ� �� �� �ϴ�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

enum TIME { NIGHT, AFTERNOON };

int di[5] = { +1, -1, 0, 0, 0 };
int dj[5] = { 0, 0, +1, -1, 0 };

int N, M, K;
string map[1000];

inline bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

int solution() {
	int answer = -1;

	// �� ��ġ���� ���� ��ȸ ���
	// -1�� ��� ���� �湮���� ���� ���
	vector<vector<int>> chanceLeftAfternoon(N, vector<int>(M, -1));
	vector<vector<int>> chanceLeftNight(N, vector<int>(M, -1));

	queue<vector<int>> bfs_queue;

	// ó������ i��ǥ / j��ǥ / ����(����� ����) / ���� �� �μ� �� �ִ� ��ȸ / ���� ����
	bfs_queue.push({ 0, 0, 1, K, AFTERNOON });
	chanceLeftAfternoon[0][0] = 0;

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front()[0];
		int cur_j = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		int cur_chanceLeft = bfs_queue.front()[3];
		int cur_time = bfs_queue.front()[4];
		bfs_queue.pop();

		if (cur_i == N - 1 && cur_j == M - 1) return cur_depth;

		for (int i = 0; i < 5; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			int next_time = (cur_time == AFTERNOON) ? NIGHT : AFTERNOON;

			if (!isInRange(next_i, next_j)) continue;

			// ����
			if (cur_time == AFTERNOON) {
				// ������ ���� ���
				if (i == 4) {
					if (chanceLeftNight[next_i][next_j] < cur_chanceLeft - 1) {
						chanceLeftNight[next_i][next_j] = cur_chanceLeft - 1;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft - 1, next_time });
					}
					continue;
				}

				// ���� ���
				if (map[next_i][next_j] == '1') {
					// �μ� ��ȸ�� ���� ��� �� ������ �� ����
					if (cur_chanceLeft == 0) continue;

					if (chanceLeftNight[next_i][next_j] < cur_chanceLeft - 1) {
						chanceLeftNight[next_i][next_j] = cur_chanceLeft - 1;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft - 1, next_time });
					}
				}
				else { // ���� ���
					if (chanceLeftNight[next_i][next_j] < cur_chanceLeft) {
						chanceLeftNight[next_i][next_j] = cur_chanceLeft;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft, next_time });
					}
				}
			}
			else { // ���� ���
				// ������ ���� ���
				if (i == 4) {
					if (chanceLeftAfternoon[next_i][next_j] < cur_chanceLeft) {
						chanceLeftAfternoon[next_i][next_j] = cur_chanceLeft;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft, next_time });
					}
					continue;
				}

				if (map[next_i][next_j] == '0') { // ���� ��츸 ���� ����
					if (chanceLeftAfternoon[next_i][next_j] < cur_chanceLeft) {
						chanceLeftAfternoon[next_i][next_j] = cur_chanceLeft;
						bfs_queue.push({ next_i, next_j, cur_depth + 1, cur_chanceLeft, next_time });
					}
				}
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << solution();

	return 0;
}
