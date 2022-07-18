#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
 N: ������ ����, ���� ����

- ���� ���� ����
 N: 3 ~ 999
 N�� Ȧ��


- ���� ��Ȳ
 N�� �־����� �� ��������� ������ ������� ������ ����ϰ�, �־��� ���� ��ǥ�� ���Ͽ���.


2. Ǯ�� ��ȹ


1. �湮�� ������ ��ġ�� ����(����� ������ ���� 0�� �ƴ� ��ġ�� ����) ������ �ݺ��Ѵ�.
 1) �� ��ġ�� ������ġ���� �� ��ġ������ �� �ִ� ��ġ���� �� �ʿ��� ���������� ������ ���� �Ŀ� ���� ���Ѵ�.
  ���� ��ġ�� ������ �� = ���� ��ġ������ ������ �� + k * k
 2) 1)���� ���� ���� ���� ����Ǿ� �ִ� ������ ���� ���� �����ϰ�,�׷��� ������ �������� �ʴ´�.

3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/
#define MAX 999

enum DIRECTION{UP, RIGHT, DOWN, LEFT};
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int snail[MAX][MAX];

int N, target;

void solution() {
	int target_i = 0;
	int target_j = 0;

	// ù ��ġ�� ���
	int cur_i = (N + 1) / 2 - 1;
	int cur_j = (N + 1) / 2 - 1;
	int cur_num = 1;
	int cur_direction = UP;

	if (cur_num == target) {
		target_i = cur_i + 1;
		target_j = cur_j + 1;
	}
	snail[cur_i][cur_j] = cur_num++;

	// ���ٿ� �� ���� ����
	for (int i = 0; i < N - 1; i++) {
		// ���� Ƚ����ŭ �ι��� �̵�
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < i + 1; j++) {
				cur_i = cur_i + di[cur_direction];
				cur_j = cur_j + dj[cur_direction];
				if (cur_num == target) {
					target_i = cur_i + 1;
					target_j = cur_j + 1;
				}
				snail[cur_i][cur_j] = cur_num++;
			}
			// ���� ��ȯ
			cur_direction++;
			cur_direction %= 4;
		}
	}

	// ������ �� �߱�
	for (int j = 0; j < N - 1; j++) {
		cur_i = cur_i + di[cur_direction];
		cur_j = cur_j + dj[cur_direction];
		if (cur_num == target) {
			target_i = cur_i + 1;
			target_j = cur_j + 1;
		}

		snail[cur_i][cur_j] = cur_num++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << snail[i][j] << " ";
		}
		cout << '\n';
	}

	cout << target_i << " " << target_j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> target;

	solution();
}