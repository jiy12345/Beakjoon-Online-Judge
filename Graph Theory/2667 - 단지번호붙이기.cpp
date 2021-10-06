#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ ũ��(���簢���̹Ƿ� ���ο� ������ ũ�� ����

�������� 0: ���� ���� ��
�������� 1: ���� �ִ� ��

- ���� ���� ����
N: 5~25

- ���� ��Ȳ
 ���� ��, ��, ��, ��� ����Ǿ� ���� ���� ���� ������� ����.

�� ��, ù �ٿ��� �� �������� ����ϰ�, �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ѵ�!

2. Ǯ�� ��ȹ
 �ϴ� 25 * 25�̰� ������ �� �ִ� ������ ��� 4�����̹Ƿ�, DFS�� ������ �� �ð��ʰ��� �߻��� �� ����.

 ���� BFS�� ������ ������ �� ���� ���� �Ұ� ����.

 �̹� ���� �� ���� ���̻� �ǹ̰� ���� �ߺ����� �湮�Ǿ�� �ȵǹǷ�, �湮�� �����Ǿ� BFS�� ť�� Ǫ�õǴ� ���� ���̻� ���� ���ٰ� ��Ÿ���� �� �� �ϴ�.


3. ��ȹ ����


*/
int N;
vector<string> map;

//         down,right,up,left => �����ְų� �� ���� �����Ƿ� ���ʰ� ���ʵ� üũ�ؾ�!
int di[4] = { 0, +1, 0, -1 };
int dj[4] = { +1, 0, -1, 0 };


int solution(int start_i, int start_j) {
	int num_of_houses = 0; 
	map[start_i][start_j] = '0'; // ������ �湮�ߴٴ� ǥ���ϱ�

	queue<vector<int>> bfs_queue; // �湮�� ��ǥ�� ������ �ִ� ť

	bfs_queue.push({ start_i, start_j}); // ù ��ǥ Ǫ��

	while (!bfs_queue.empty()) {

		vector<int> cur_node = bfs_queue.front();
		bfs_queue.pop();
		num_of_houses++; // pop�Ҷ����� �� �ϳ��� ����

		int cur_i = cur_node[0];
		int cur_j = cur_node[1];

		// ��, �Ʒ�, ����, ������ Ž��
		// �� �� �ִ� ������ 1�� �ִ� �������θ� Ž��
		for (int i = 0; i < 4; i++) {
			if (map[cur_i + di[i]][cur_j + dj[i]] == '1') {
				map[cur_i + di[i]][cur_j + dj[i]] = '0'; // �ߺ� �湮 ������ ���� �̸� �湮 ǥ���ϱ�
				bfs_queue.push({ cur_i + di[i], cur_j + dj[i]});
			}
		}
	}
	return num_of_houses;
}

int main() {

	cin >> N;

	string map_row; // �̷��� �� �� ���� �Է¹ޱ� ���� ����
	vector<int> num_of_houses_list;

	string wall = ""; // ���� �Ʒ� �� �����
	for (int i = 0; i < N + 2; i++) {
		wall += "0";
	}

	map.push_back(wall); // �̷��� �� �� ǥ��

	for (int i = 0; i < N; i++) {
		cin >> map_row;
		map.push_back("0" + map_row + "0"); // ���ʰ� ������ ���� �ٿ��� �Է�
	}

	map.push_back(wall); // �̷��� �Ʒ��� �� ǥ��

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '1') {
				num_of_houses_list.push_back(solution(i, j));
			}
		}
	}

	cout << num_of_houses_list.size() << endl;

	sort(num_of_houses_list.begin(), num_of_houses_list.end());

	for (int i = 0; i < num_of_houses_list.size(); i++) {
		cout << num_of_houses_list[i] << endl;;
	}
	
	return 0;
}