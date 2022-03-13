#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: ��ٸ��� ��
M: ���� ��

- ���� ���� ����


- ���� ��Ȳ
�� k�� d1, d2, ..., dk�� �̷���� ����Ŭ�� ���Ǵ� �Ʒ��� ����.

 - ��� k���� ���� ���� �ٸ���.
 - k�� 4���� ũ�ų� ����.
 - ��� ���� ���� ����.
 - ��� 1 �� i �� k-1�� ���ؼ�, di�� di+1�� �����ϴ�. ��, dk�� d1�� �����ؾ� �Ѵ�. �� ���� �����ϴٴ� ���� ������ ���� ����ִ� ĭ�� ���� �����Ѵٴ� �ǹ��̴�.

�������� ���°� �־����� ��, ����Ŭ�� �����ϴ��� �ƴ��� ���θ� �Ǵ��϶�.

 2. Ǯ�� ��ȹ
 ���� �ּ� � �μ���� �ϴ����� ���� �����̹Ƿ�, ���� �μ��� ���� ����� �߻��Ѵٰ� ���� �ȴ�.

 ���� 0 - 1 BFS��� �� �� �ִ�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N, M;
bool isVisited[101];
int ladderAndSnake[101];


int solution() {
	int answer = 0;

	queue<pair<int, int>> bfs_queue;

	bfs_queue.push(make_pair(1, 0));
	isVisited[0] = true;

	while (!bfs_queue.empty()) {
		int cur_loc = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		cout << "cur_loc: " << cur_loc << endl;
		cout << "cur_depth: " << cur_depth << endl;

		if (cur_loc == 100) {
			answer = cur_depth;
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int next_loc = cur_loc + i;

			if (next_loc <= 100) {
				cout << "next_loc: " << next_loc << endl;
				if (ladderAndSnake[next_loc] != 0) next_loc = ladderAndSnake[next_loc];
				cout << "next_loc: " << next_loc << endl << endl;

				if (isVisited[next_loc] == false) {
					isVisited[next_loc] = true;
					bfs_queue.push(make_pair(next_loc, cur_depth + 1));
				}
			}

		}
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int start, end;
		cin >> start >> end;
		ladderAndSnake[start] = end;
	}

	cout << solution();

	return 0;
}