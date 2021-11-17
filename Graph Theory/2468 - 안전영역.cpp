#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

/*
1. ���� �м�
 - ����
N: ������ ����, ���� ����

 - ���� ���� ����
N:2~100
�� ��ġ�� ����: 1~100



2. Ǯ�� ��ȹ
�ټ� �����غ�������, ��� ���̿� ���� Ž���� �����ϰ�,

�� Ž������ ��� ������ Ž���ϸ� �� ������ ���� ������ ��� bfs�� �����ϴ� �������� ����




3. ��ȹ ����


*/

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int region[102][102];
int N;

// region: �� ��ġ�� ���������̸� true, �ƴϸ� false
void bfs(int cur_region[102][102], pair<int, int> cur_loc, int water_level) {
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(cur_loc);

	while (!bfs_queue.empty()) {
		pair<int, int>loc = bfs_queue.front();
		bfs_queue.pop();

		for (int i = 0;i < 4;i++) {
			int cur_i = loc.first - dx[i];
			int cur_j = loc.second - dy[i];

			if (cur_region[cur_i][cur_j] - water_level > 0) {
				// �� �̻� Ž������ �ʵ��� ���� ���� ���̷� ����
				cur_region[cur_i][cur_j] = 0;
				bfs_queue.push({ cur_i, cur_j });
			}
		}
	}
}

int find_safe_zone(int cur_region[102][102], int water_level) {
	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			// �� ��ġ�� ħ������ ���� ��ġ���
			if (cur_region[i][j] - water_level > 0) {
				cnt++;
				// �� ��ġ���� vfs ����
				bfs(cur_region, { i,j }, water_level);
			}
		}
	}
	return cnt;
}

int solution(int max_num) {
	int answer = 0;

	// ������ ��� ���̿� ���ؼ� üũ
	for (int i = 0;i <= max_num;i++) {
		int cur_region[102][102];
		copy(&region[0][0], &region[0][0] + 102 * 102 , &cur_region[0][0]);
		answer = max(answer, find_safe_zone(cur_region, i));
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	int max_num = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> region[i][j];
			max_num = max(max_num, region[i][j]);
		}
	}

	cout << solution(max_num);

	return 0;
}