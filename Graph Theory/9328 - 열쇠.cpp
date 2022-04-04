#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
#include<queue>
using namespace std;

int h, w;
char map[102][102]; // �ٱ��� ������ �ξ� �� �ٷ� ���� ��ġ�� �����Ӱ� ���ƴٴ� �� �ֵ��� ��
bool isVisited[102][102];
int key;

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

bool isInRange(int i, int j) {
	return 0 <= i && i <= h + 1 && 0 <= j && j <= w + 1;
}

int solution() {
	int docNum = 0;

	queue<pair<int, int>> bfs_queue;
	queue<pair<int, int>> doorPos[26]; // ������ ��ġ�� ����س��� ť
	bfs_queue.push({ 0, 0 });
	isVisited[0][0] = true;
	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isInRange(next_i, next_j) == false) continue;
			if (map[next_i][next_j] == '*' || isVisited[next_i][next_j] == true) continue;

			isVisited[next_i][next_j] = true;

			// ���� ���
			if (isupper(map[next_i][next_j])) {
				// ������ ���� ���
				if (((1 << (map[next_i][next_j] - 'A')) & key) != 0) bfs_queue.push({ next_i, next_j });
				// �ƴ� ��� �� ��ġ ����ϱ�
				else doorPos[map[next_i][next_j] - 'A'].push({ next_i, next_j });
			}
			else if (islower(map[next_i][next_j])) {
				bfs_queue.push({ next_i, next_j });
				// ���� ȹ������ ���� Ű�� ���
				if (((1 << (map[next_i][next_j] - 'a')) ^ key) != key) {
					// Ű ��Ͽ� �߰�
					key |= (1 << (map[next_i][next_j] - 'a'));

					while (!doorPos[map[next_i][next_j] - 'a'].empty()) {
						// �� ���� ��ġ�� �湮�� �� �ֵ��� ��
						bfs_queue.push(doorPos[map[next_i][next_j] - 'a'].front());
						doorPos[map[next_i][next_j] - 'a'].pop();
					}
				}
			}
			else {
				bfs_queue.push({ next_i, next_j });
				if (map[next_i][next_j] == '$')
					docNum++;
			}
		}
	}

	return docNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(map, 0, sizeof(map));
		memset(isVisited, false, sizeof(isVisited));
		key = 0;

		cin >> h >> w;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> map[i][j];

		string keyString;
		cin >> keyString;
		if (keyString != "0") {
			for (int i = 0; i < keyString.size(); i++) {
				key |= (1 << (keyString[i] - 97));
			}
		}

		cout << solution() << '\n';
	}

	return 0;
}