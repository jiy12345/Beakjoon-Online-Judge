#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
S: �̸�Ƽ���� ����

- ���� ���� ����
S: 2 ~ 1,000

- ���� ��Ȳ
 1���� �̸�Ƽ���� �ԷµǾ� ���� ��, ������ ���� 3���� ������ ����Ͽ� �̸�Ƽ���� S�� ������� �Ѵ�.

 1. ȭ�鿡 �ִ� �̸�Ƽ���� ���� �����Ͽ� Ŭ�����忡 ����
 2. Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ�
 3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ� ����

2. Ǯ�� ��ȹ

�������� BFS �����̴�

���� �湮���� ����(ť�� Ǫ�õ��� ����) ����̸�
3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define MAX 1001

bool isVisited[MAX][MAX];

int solution(int S) {
	queue<vector<int>>bfs_queue;

	int timeSpent = -1;

	// ���� �̸�Ƽ���� ���� / Ŭ�����忡 ����� �̸�Ƽ���� �� / ���� �ɸ� �ð�
	bfs_queue.push({1, 0, 0});
	isVisited[1][0] = true;


	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front()[0];
		int cur_clipBoard = bfs_queue.front()[1];
		int cur_depth = bfs_queue.front()[2];
		bfs_queue.pop();

		//cout << "cur_num: " << cur_num << ", ";
		//cout << "cur_clipBoard: " << cur_clipBoard << ", ";
		//cout << "cur_depth: " << cur_depth << endl;

		//cout << "cur_num: " << cur_num << ", ";
		//cout << "bfs_queue.size(): " << bfs_queue.size() << endl;

		if (cur_num == S) {
			timeSpent = cur_depth;
			break;
		}

		// 1. Ŭ�����忡 ����
		if (isVisited[cur_num][cur_num] == false) {
			isVisited[cur_num][cur_num] = true;
			bfs_queue.push({ cur_num, cur_num, cur_depth + 1 });
		}

		// 2. Ŭ�����忡 �ִ� ���� �ٿ��ֱ�
		int next_num = cur_num + cur_clipBoard;
		if (next_num < MAX && isVisited[next_num][cur_clipBoard] == false && cur_clipBoard != 0) {
			isVisited[next_num][cur_clipBoard] = true;
			bfs_queue.push({ next_num, cur_clipBoard, cur_depth + 1 });
		}

		// 3. ȭ�鿡 �ִ� �̸�Ƽ�� ����
		next_num = cur_num - 1;
		if (next_num >= 0 && isVisited[next_num][cur_clipBoard] == false) {
			isVisited[next_num][cur_clipBoard] = true;
			bfs_queue.push({ next_num, cur_clipBoard, cur_depth + 1 });
		}
	}

	return timeSpent;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int S;

	cin >> S;

	cout << solution(S);

	return 0;
}