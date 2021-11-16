#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�

- ����
w: �ʺ�
h: ����

- ���� ���� ����
w, h: 0~50!

- ���� ��Ȳ
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� ������, �� �׽�Ʈ ���̽������� �ʺ� w�� ���� h�� �־�����,

�ٸ� ���簢���� ����, ����, �Ǵ� �밢������ ����Ǿ� �ִ� �簢���� ������ �ϳ��� ���̶�� �� ��,

������ 1�� ��, 0�� �ٴٷ� �־��� ��, ���� ������ ���Ͽ���

2. Ǯ�� ��ȹ
��� 1�� �κ�(��)�� ���� BFS�� �����ϸ�, 

3. ��ȹ ����


*/

int dx[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };


void bfs(int map[][52], pair<int, int> start_node) {
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(start_node);

	while (!bfs_queue.empty()) {
		pair<int, int> cur_node = bfs_queue.front();
		bfs_queue.pop();

		// 8 ���⿡ ���� ��� üũ
		for (int i = 0;i < 8;i++) {
			int cur_x = cur_node.first + dx[i];
			int cur_y = cur_node.second + dy[i];

			// �̹� Ž���� ��� ǥ��
			if (map[cur_x][cur_y] == 1) {
				map[cur_x][cur_y] = 0;
				bfs_queue.push({ cur_x, cur_y });
			}
		}
	}
}

int solution(int map[][52], int w, int h) {
	int cnt = 0;

	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			if (map[i][j] == 1) {
				cnt++;
				bfs(map, { i, j });
			}
		}
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int w, h;
	while (true) {
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		int map[52][52];

		for (int i = 1;i <= h;i++) {
			for (int j = 1;j <= w;j++) {
				cin >> map[i][j];
			}
		}

		cout << solution(map, w, h) << "\n";
	}

	return 0;
}