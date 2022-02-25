#include<iostream>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: �迭�� ���� ����
M: �迭�� ���� ����
R: ȸ����ų Ƚ��
Aij: �־����� �迭�� i�� j�� ����

- ���� ���� ����
N, M: 2 ~ 300
N, M�� ¦��
R: 1 ~ 1,000
Aij: 1 ~ 10,000,000

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


int N, M, R;
int A[300][300];
int A_temp[300][300];

void rotate(int numOfRep) {
	copy(&A[0][0], &A[0][0] + 300 * 300, &A_temp[0][0]);

	// �� -> ��, �� -> ��
	for (int i = 0; i < numOfRep; i++) {
		for (int j = i; j < M - i - 1; j++) {
			A[i][j] = A_temp[i][j + 1];
			A[N - i - 1][j + 1] = A_temp[N - i - 1][j];
		}
	}

	// �� -> ��, �� -> ��
	for (int i = 0; i < numOfRep; i++) {
		for (int j = i; j < N - i - 1; j++) {
			A[j + 1][i] = A_temp[j][i];
			A[j][M - i - 1] = A_temp[j + 1][M - i - 1];
		}
	}
}


void solution() {
	int numOfRep = min(N, M) / 2;

	for (int i = 0; i < R; i++) {
		rotate(numOfRep);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}