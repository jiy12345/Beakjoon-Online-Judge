#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;

/*
1. ���� �м�
- ����
S: ���� �ִ� ��
G: ������ ��
F: ���� ���� ��
U: U��ư�� �ö��� �� �ѹ��� U���� �ö󰡰� ��
D: D��ư�� �ö��� �� �ѹ��� D���� �ö󰡰� ��

- ���� ���� ����
1 �� S, G �� F �� 1000000
0 �� U, D �� 1000000

�ǹ��� 1������ ����

- ���� ��Ȳ
S ������ G������ ���� ���� ������ �ϴ� ��ư ���� �ּڰ��� ����Ѵ�.

���� ���������ͷ� �̵��� �� ���� ���� "use the stairs"�� ����Ѵ�.

����, U�� ��, D�� �Ʒ��� ���� ���� ���� �������� �ʴ´�.

2. Ǯ�� ��ȹ
�� bfs

3. ��ȹ ����

bfs�� �׷��� �Ÿ��� ����� ��尡 ���� ���´�.

�Ÿ��� ����� ���� ȸ������ ���ٴ� ���� �����ϴ°�?
�׷��� �ʴ�. ���� priority_queue�� ����Ͽ� ȸ�� ���� ���� ���ĵǵ��� �ؾ��� �� �ϴ�.


*/

#define MAX 1000001

int F, S, G, U, D;
bool isVisited[MAX];
int movement[2];

bool isInRange(int cur_floor) {
	return 1 <= cur_floor && cur_floor <= F;
}

int solution() {
	int answer = -1;

	// ���� ��ǥ / ����(��ư ���� Ƚ��)
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ S, 0 });
	isVisited[S] = true;

	while (!bfs_queue.empty()) {
		int cur_floor = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		
		if (cur_floor == G) {
			answer = cur_depth;
			break;
		}
		
		for (int i = 0; i < 2; i++) {
			int next_floor = cur_floor + movement[i];
			if (isInRange(next_floor) && isVisited[next_floor] == false) {
				bfs_queue.push({ next_floor, cur_depth + 1 });
				isVisited[next_floor] = true;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	movement[0] = U;
	movement[1] = -D;


	int answer = solution();

	cout << ((answer == -1) ? "use the stairs" : to_string(answer)); 

	return 0;
}
