#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
1. ���� �м�
- ����
N: �������� ���� ��ġ
K: ������ ���� �̤�ġ

- ���� ���� ����
N: 0 ~ 100,000
K: 0 ~ 100,000

- ���� ��Ȳ
 �����̿� ������ ��ġ�� �־�����, �����̴� ������ ���� �̵��Ѵٰ� ����.

 �������� �� ��ġ�� X�� ��,

 - �ȱ�: 1���Ŀ� X - 1 or X + 1
 - �����̵�: 0�� �Ŀ� 2 * X

 �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

2. Ǯ�� ��ȹ

0 - 1 �� ������ ���� �ٸ� ����ġ�� ������ �ֱ�� ������, 

�켱���� ť�� �̵��Ѵٸ�?
 => � ��带 ���� �湮 �ߴٰ� ���� ��, �� �湮���� �ɸ� �ð��� �ִܽð��̶�� ������ �� ���� ������ �ȵȴ�. 

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

inline bool isInRange(int X) {
	return (0 <= X && X <= 200000);
}

int solution(int N, int K) {
	int distance[200001];
	int timeSpent = 0;

	fill_n(distance, 200001, 1e9);
	distance[N] = 0;

	deque<int>bfs_queue;

	bfs_queue.push_back(N);

	while (!bfs_queue.empty()) {
		int cur_location = bfs_queue.front();
		bfs_queue.pop_front();

		if (cur_location == K) {
			break;
		}

		int next_location = cur_location + 1;
		if (isInRange(next_location) && distance[cur_location] + 1 < distance[next_location]) {
			distance[next_location] = distance[cur_location] + 1;
			bfs_queue.push_back(next_location);
		}

		next_location = cur_location - 1;
		if (isInRange(next_location) && distance[cur_location] + 1 < distance[next_location]) {
			distance[next_location] = distance[cur_location] + 1;
			bfs_queue.push_back(next_location);
		}

		next_location = 2 * cur_location;
		if (isInRange(next_location) && distance[cur_location] < distance[next_location]) {
			distance[next_location] = distance[cur_location];
			bfs_queue.push_front(next_location);
		}
	}

	return distance[K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	cout << solution(N, K);

	return 0;
}