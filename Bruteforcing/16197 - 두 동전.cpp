#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*
1. ���� �м�
- ����
N: ���� ���� ���� ����
M: ���� ���� ���� ����

- ���� ���� ����
N, M: 20

- ���� ��Ȳ
����� ���̳� ��ĭ���� �̷���� �ְ�,

������ �� ���� ��ĭ�� ������ �ְ�,

 �� ������ "����", "������", "��", "�Ʒ�"�� ���� 4���� �������� �̵��� �� ������, 

������ ������ ���� �̵��Ѵٰ� �� ��,

- ������ �̵��Ϸ��� ĭ�� ���̸�, ������ �̵����� �ʴ´�.
- ������ �̵��Ϸ��� ���⿡ ĭ�� ������ ������ ���� �ٱ����� ��������.
- �� ���� ��쿡�� �̵��Ϸ��� �������� �� ĭ �̵��Ѵ�.�̵��Ϸ��� ĭ�� ������ �ִ� ��쿡�� �� ĭ �̵��Ѵ�.

 �� ���� �� �ϳ��� ���忡�� ����߸��� ���� �ؾ��ϴ� �̵��� �ּ� Ƚ���� ����Ѵ�.

 ���� �� ������ ����߸� �� ���ų�, ����߸��� ���� ��ư�� 10������ ���� ������ �Ѵٸ� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

#define WALL true
#define EMPTY false

int di[4] = { 0, 0, -1, +1 };
int dj[4] = { -1, +1, 0, 0 };

int N, M;
bool isVisited[22][22][22][22];
bool Map[22][22];

bool isInRange(int i, int j) {
	return 1 <= i && i <= N && 1 <= j && j <= M;
}

int solution(vector<pair<int, int>> coinCoord) {
	
	int answer = -1;

	queue<pair<int, vector<pair<int, int>>>>bfs_queue;

	bfs_queue.push(make_pair(0, coinCoord));

	

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front().first;
		int cur_i1 = bfs_queue.front().second[0].first;
		int cur_j1 = bfs_queue.front().second[0].second;
		int cur_i2 = bfs_queue.front().second[1].first;
		int cur_j2 = bfs_queue.front().second[1].second;
		bfs_queue.pop();

		// 11�� ���� ��Ȳ�� �߻��ϸ� ����������
		if (cur_depth == 11) break;

		if (isInRange(cur_i1, cur_j1) && isInRange(cur_i2, cur_j2)) {
			// �Ѵ� ���� ���� ��쿡�� �״�� bfs ����
		}
		else if (!isInRange(cur_i1, cur_j1) && !isInRange(cur_i2, cur_j2)) {
			// �Ѵ� ���� ���� ���� ���� Ž�� ������� �Ѿ
			continue;
		}
		else {
			// �ϳ��� ���� ���� ��� Ž�� �����ϰ� ��������
			answer = cur_depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_i1 = cur_i1 + di[i];
			int next_j1 = cur_j1 + dj[i];
			int next_i2 = cur_i2 + di[i];
			int next_j2 = cur_j2 + dj[i];

			// ���� ��ġ�� ���̸� �� ��ġ�� ������
			if (Map[next_i1][next_j1] == WALL) {
				next_i1 = cur_i1;
				next_j1 = cur_j1;
			}
			if (Map[next_i2][next_j2] == WALL) {
				next_i2 = cur_i2;
				next_j2 = cur_j2;
			}

			// �� ������ ��ġ�� ������ ���� ��Ȳ�� ���� Ž�� ����
			if (!isVisited[next_i1][next_j1][next_i2][next_j2]) {
				isVisited[next_i1][next_j1][next_i2][next_j2] = true;
				bfs_queue.push({ cur_depth + 1, {{next_i1, next_j1}, {next_i2, next_j2}} });
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<pair<int, int>> coinCoord;

	for (int i = 0; i <= N + 1; i++) {
		if (i == 0 || i == N + 1) continue;
		string row;
		cin >> row;
		for (int j = 0; j <= M + 1; j++) {
			if (j == 0 || j == M + 1) continue;
			if (row[j - 1] != 'o') Map[i][j] = (row[j - 1] == '#');
			else {
				Map[i][j] = false;
				coinCoord.push_back(make_pair(i, j));
			}
		}
	}

	cout << solution(coinCoord);

	return 0;
}