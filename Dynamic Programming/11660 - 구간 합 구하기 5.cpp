#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�

- ����
N: ǥ�� ũ��
M: ���� ���ؾ� �ϴ� Ƚ��

- ���� ���� ����
N: 1~1,024
M: 1~100,000



- ���� ��Ȳ
 ǥ�� �ִ� ����� 

M���� �� ���� �������� (x1, y1, x2, y2) �� �־��� ��
(x1, y1)���� (x2, y2)������ ���� ���� ����Ѵ�. (x1 �� x2, y1 �� y2)

2. Ǯ�� ��ȹ


�ϴ� �� ��ġ�� �κ����� ������ ���� ��Ÿ�� �� �ִ�.

dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

���� ���� ���� ������ ������ dp[i-1][j] + dp[i][j-1]�� ���ϸ� �������� �������� �κ��� �ֱ� ������ �� �κ��� ����� �ϱ� �����̴�.


�̷��� ���ϰ� ����, ������ ���� ���� ���� ������ ���� ���� �� �ִ�.

(x1, y1)���� (x2, y2)������ �� = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];





3. ��ȹ ����


*/

int N, M;


int table[1025][1025];
int dp[1025][1025];

void solution() {
	int x1, y1, x2, y2;

	for (int i = 0;i < M;i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout<< dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	// �Է� ������ �� ��ġ������ �� ���ϱ�
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> table[i][j];
			dp[i][j] = table[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	solution();

	return 0;
}