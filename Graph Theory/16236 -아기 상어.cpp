#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ ����, ���� ����

- ���� ���� ����
N: 2~20


 - ���� ��Ȳ
 �Ʊ� �� ������ ���� ��Ģ�� ���� �̵��Ѵٰ� �� ��,

 - �� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
 - ���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
 - ���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּڰ��̴�.
�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.

2. Ǯ�� ��ȹ

�� ��ġ�κ��� ���� ���� ����� ��ġ������ bfs�� �����Ͽ�, �� �ɸ��� �ð�(����� ����)�� ���ϸ� �� �� �ϴ�!


3. ��ȹ ����


*/

int N;
int space[22][22];

//		   �� -> ���� ������ ����
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };


// ���� ��ġ ��ȯ
int bfs(int curSpace[][22], pair<int, int>& startLocation, int curSize) {

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>bfs_queue;

	bfs_queue.push({ 0, startLocation.first, startLocation.second, 0});

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.top()[0];
		int cur_i = bfs_queue.top()[1];
		int cur_j = bfs_queue.top()[2];
		int cur_fishSize = bfs_queue.top()[3];
		bfs_queue.pop();

		// ���� �� �ִ� ����⿴�� ���
		if (cur_fishSize < curSize && cur_fishSize != 0) {
			// ���� bfs�� ���� ��� ��ġ ����
			startLocation = make_pair(cur_i, cur_j);
			return cur_depth;
		}

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (curSpace[next_i][next_j] <= curSize) {
				bfs_queue.push({ cur_depth + 1, next_i, next_j, curSpace[next_i][next_j] });
				curSpace[next_i][next_j] = 100;
			}
		}
	}

	// �� Ž���������� �ұ��ϰ� ���� �� �ִ� ����⸦ ã�� ���ߴٸ� 0 ��ȯ
	return 0;
}



int solution(pair<int, int> startLocation) {
	int answer = 0; // �� �ð��� ��
	int curSize = 2; // �ʱ� ũ��� 2
	int numEat = 0;

	while (true) {
		int curSpace[22][22];

		copy(&space[0][0], &space[0][0] + (22 * 22), &curSpace[0][0]);

		int curTime = bfs(curSpace, startLocation, curSize);
		numEat++;
		// �Ծ����Ƿ� �� ĭ���� ǥ��
		space[startLocation.first][startLocation.second] = 0;

		// ���� ����⸦ ã�� ���ϸ�
		if (curTime == 0) {
			break;
		}
		
		answer += curTime;

		// ��ǥ Ƚ����ŭ ���� ��� ���� Ű���
		if (numEat == curSize) {
			numEat = 0;
			curSize++;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> startLocation;

	cin >> N;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			// �ܺ� �θ���
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				space[i][j] = 100;
			}
			else {
				int value;
				cin >> value;
				if (value == 9) {
					startLocation = make_pair(i, j);
					space[i][j] = 0;
				}
				else {
					space[i][j] = value;
				}
			}
		}
	}

	cout << solution(startLocation);

	return 0;
}