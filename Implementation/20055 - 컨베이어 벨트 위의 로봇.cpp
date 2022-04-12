#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

/*
1. ���� �м�
- ����
N: �����̾� ��Ʈ�� ����
K: �������� 0�� ĭ�� ������ K�� �̻��̸� ���� ����
Ai: i�� ĭ�� ������
 => 1�� ��ġ: �ø��� ��ġ
 => N�� ��ġ: ������ ��ġ


- ���� ���� ����
N: 1 ~ 7
K: 1 ~ 2N
Ai: 1 ~ 1,000

- ���� ��Ȳ

��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.
���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�.
  �κ��� �̵��ϱ� ���ؼ��� �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� ���� �־�� �Ѵ�.
�ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
�������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.


2. Ǯ�� ��ȹ
 ȸ�� ��� ������ ȸ�� ��Ű��, ������ ���� ��Ģ�� �������� ����.




3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/


int N, K, numOfZero;

deque<int> A;

void rotate(deque<bool>& hasRobot) {
	hasRobot.push_front(hasRobot.back());
	hasRobot.pop_back();
	// ������ ��ġ���� �κ� ����
	hasRobot[N - 1] = false;

	A.push_front(A.back());
	A.pop_back();
}

void robotMove(deque<bool>& hasRobot) {
	for (int i = N - 2; i >= 0; i--) {
		// �ش� ��ġ�� �κ��� ���� ��� ���� x
		if (hasRobot[i] == false) continue;
		
		// �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� ���� �־��
		if (hasRobot[i + 1] == false && A[i + 1] >= 1) {
			// ���� ĭ���� �κ� �ű��
			hasRobot[i] = false;
			hasRobot[i + 1] = true;
			// �̵��� ĭ�� ������ 1 ����
			A[i + 1]--;

			// �������� 0�� ĭ�� ���� ����
			if (A[i + 1] == 0) numOfZero++;
		}
	}

	// ������ ��ġ���� �κ� ����
	hasRobot[N - 1] = false;
}

int solution() {
	int step_cnt = 0;

	deque<bool> hasRobot(2 * N, false);


	while (true) {
		step_cnt++;
		// 1. ��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� ��ĭ ȸ��
		rotate(hasRobot);

		// 2. ���� ���� ��Ʈ�� �ö� �κ����� ��Ʈ�� ȸ���ϴ� �������� ��ĭ �̵��� �� �մٸ� �̵�
		robotMove(hasRobot);

		// 4. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴ϶�� �ø��� ��ġ�� �κ��� �ø���.
		if (A[0] >= 1) {
			hasRobot.front() = true;
			A[0]--;

			// �������� 0�� ĭ�� ���� ����
			if (A[0] == 0) numOfZero++;
		}

		if (numOfZero >= K) break;
	}

	return step_cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++) {
		int Ai;
		cin >> Ai;
		A.push_back(Ai);
	}

	cout << solution();

	return 0;
}