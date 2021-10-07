#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�

- ����
N: �� ��ǻ���� ��



- ���� ���� ����
N:1~100

- ���� ��Ȳ
 ��ǻ�Ͱ��� ���� ������ �־�����, 1�� ��ǻ�ͺ��� �����̷����� �ɸ���, ����� ��� ��ǻ�Ͱ� �� ���̷����� �ɸ��ٰ� �� ��,
 �� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ���϶�

2. Ǯ�� ��ȹ
�����Ȳ�� ��Ȯ���� �ʾ� ��Ȯ�� üũ�� ���� ������, �̷��� ������ ������ ���� �� �ִ� ����, �׸��� �ѹ����� �湮�� ������ �Ǵ� ������ 
BFS�� �����ϵ� �湮 ǥ�ø� ť�� Ǫ���Ͽ� �ߺ� �湮 ���� �ʵ��� �ϴ� ���� ���� ȿ�����̴�!

���� ��ǻ���� ���� 100���� �׸� ���� �����Ƿ� 100 x 100 ������ �迭�� ���� �� ��ǻ�Ͱ��� ������ ǥ���ϸ� �� �� �ϴ�!

���� �ڼ��� ��ȹ�� ������ ����.

1. 2���� bool�� �迭�� ���������� �Է¹޾� ����� ���� true, �������� false�� ǥ���Ѵ�.
2. 1�� ť�� Ǫ���ϰ�, BFS Ž���� �����Ѵ�.



3. ��ȹ ����


*/
int N; // ��ǻ�� ��
int num_of_link;
bool link_info[101][101] = { {false, }, };
bool is_visited[101] = { false };

int solution(int start_computer) {
	int answer = 0;

	queue<int> bfs_queue;

	is_visited[start_computer] = true;

	bfs_queue.push(start_computer);

	while (!bfs_queue.empty()) {
		int cur_computer = bfs_queue.front();
		bfs_queue.pop();
		answer++;

		for (int i = 1; i <= N; i++) {
			if (link_info[cur_computer][i] == true && is_visited[i] == false) {
				is_visited[i] = true; // �ߺ� �湮 ������ ���� ť�� Ǫ�õ� �� �湮 ǥ�� 
				bfs_queue.push(i);
			}
		}
	}
	return answer;
}

int main() {

	cin >> N;
	cin >> num_of_link;

	// ����� ����!
	int start, end;
	for (int i = 0; i < num_of_link; i++) {
		cin >> start >> end;
		link_info[start][end] = true;
		link_info[end][start] = true;
	}

	// 1�� ��ǻ�ʹ� ���ֱ� ���� 1 ���ֱ�!
	cout << (solution(1) - 1);
}