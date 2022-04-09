#include <iostream>
#include <vector>
using namespace std;

/*
1. ���� �м�
- ����
 H, W: �迭 A�� ũ��
 X, Y: �迭 A�� �̵� �󸶳� �̵����״°�?

- ���� ���� ����
H, W: 2~300

1 �� X < H
1 �� Y < W
0 �� Bi,j �� 1,000

- ���� ��Ȳ

�迭 B�� (i, j)�� ����ִ� ���� �Ʒ� 3�� �� �ϳ��̴�.

(i, j)�� �� �迭 ��ο� ���Ե��� ������, Bi,j = 0�̴�.
(i, j)�� �� �迭 ��ο� ���ԵǸ�, Bi,j = Ai,j + Ai-X,j-Y�̴�.
(i, j)�� �� �迭 �� �ϳ��� ���ԵǸ�, Bi,j = Ai,j �Ǵ� Ai-X,j-Y�̴�.

 �迭 A�� ���Ͽ���

2. Ǯ�� ��ȹ


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int H, W, X, Y;
int B[600][600];
int A[300][300];

void solution() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i - X >= 0 && j - Y >= 0) {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            }
            else {
                A[i][j] = B[i][j];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}

	solution();

	return 0;
}