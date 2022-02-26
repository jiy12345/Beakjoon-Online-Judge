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

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;	// �������� �����ش�.

		a = b;
		b = r;
	}
	return a;
}

long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

int N, M, R;
int A1[300][300];
int A2[300][300];
bool isOne = true; // 1�� �迭�� ���� ����� ��ü �迭�� ����

void rotate(int cur_row, int cur_R) {

	for (int i = 0; i < cur_R; i++) {
		if (isOne) {
			// �� -> ��, �� -> ��
			for (int j = cur_row; j < M - cur_row - 1; j++) {
				A2[cur_row][j] = A1[cur_row][j + 1];
				A2[N - cur_row - 1][j + 1] = A1[N - cur_row - 1][j];
			}

			// �� -> ��, �� -> ��
			for (int j = cur_row; j < N - cur_row - 1; j++) {
				A2[j + 1][cur_row] = A1[j][cur_row];
				A2[j][M - cur_row - 1] = A1[j + 1][M - cur_row - 1];
			}
			isOne = false;
		}
		else {
			// �� -> ��, �� -> ��
			for (int j = cur_row; j < M - cur_row - 1; j++) {
				A1[cur_row][j] = A2[cur_row][j + 1];
				A1[N - cur_row - 1][j + 1] = A2[N - cur_row - 1][j];
			}

			// �� -> ��, �� -> ��
			for (int j = cur_row; j < N - cur_row - 1; j++) {
				A1[j + 1][cur_row] = A2[j][cur_row];
				A1[j][M - cur_row - 1] = A2[j + 1][M - cur_row - 1];
			}
			isOne = true;
		}
	}

	if (cur_R % 2 != 0) {
		copy(&A2[0][0], &A2[0][0] + 300 * 300, &A1[0][0]);
	}
}


void solution() {
	copy(&A1[0][0], &A1[0][0] + 300 * 300, &A2[0][0]);

	int cnt = 0;
	int n = N;
	int m = M;

	while (true) {
		int cur_R = R % (2 * n + 2 * m - 4);
		rotate(cnt, cur_R);
		if (n == 2 || m == 2) {
			break;
		}
		n -= 2;
		m -= 2;
		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A1[i][j];
		}
	}

	solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A1[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}