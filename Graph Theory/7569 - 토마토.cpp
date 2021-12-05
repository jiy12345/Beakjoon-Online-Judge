#include<iostream>
#include<queue>
using namespace std;

int tomato_box[100][100][100];
int M, N, H;

//           ��  ��  ���� ��  �Ʒ� ��
int di[6] = { +1, -1,  0,  0,  0,  0 };
int dj[6] = {  0,  0, +1, -1,  0,  0 };
int dk[6] = {  0,  0,  0,  0, +1, -1 };

int solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int answer = 0;
	// BFS�� �����ϱ� ���� ť
	queue<vector<int>> bfs_queue;

	// �� ������(ó���� �����ϴ� ���� �丶��)�� ť�� Ǫ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0;k < H;k++) {
				if (tomato_box[i][j][k] == 1) {
					bfs_queue.push({ i, j, k, 0 });
				}
			}
		}
	}

	// �丶�� ������ ����
	while (!bfs_queue.empty()) {
		// ���� ��� ��������
		vector<int> cur_node;
		cur_node = bfs_queue.front();
		bfs_queue.pop();
		answer = cur_node[3]; // ���� �� �� �ִ� �� �� ���� ���̰� ����(�Ÿ��� �����) ������ �湮�ϹǷ�, �׻� ���̰� �ʹµ� �ɸ��� �Ⱓ�� ��!

		for (int j = 0; j < 6; j++) {
			// ������ ������ ����� ��ǥ����
			int next_i = cur_node[0] + di[j];
			int next_j = cur_node[1] + dj[j];
			int next_k = cur_node[2] + dk[j];
			if (0 <= next_i && next_i < N && 0 <= next_j && next_j < M && 0 <= next_k && next_k < H) { // ���� �� ���� ���� ����
				if (tomato_box[next_i][next_j][next_k] == 0) {
					tomato_box[next_i][next_j][next_k] = 1; // �ߺ� �湮 ������ ���� �;��ٴ� ǥ�� �̸� �س���
					bfs_queue.push({ next_i, next_j, next_k, cur_node[3] + 1 });
				}
			}
		}
	}

	// ������ �丶�䰡 ���� ���Ҵٸ� -1��ȯ
	for (int k = 0;k < H;k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tomato_box[i][j][k] == 0) {
					return -1;
				}
			}
		}
	}

	// ��� �;��ٸ� �ּ� ��¥ ��ȯ
	return answer;
}

int main() {
	cin >> M >> N >> H;
	for (int k = 0;k < H;k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tomato_box[i][j][k];
			}
		}
	}

	cout << solution();
}