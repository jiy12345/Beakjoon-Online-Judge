#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N, M: �������� ũ��
K: ������ ���� ����

- ���� ���� ����
N, M: 1~10
K: 1~min(4, NxM)
�����ǿ� ����ִ� ��: -10,000~10,000

�׻� K���� ĭ�� ������ �� �ִ� �Է¸� �־�����.


�޸� ����: 512 MB

- ���� ��Ȳ
 NxM ���ڿ� ������ ���� �� K���� ���� �����Ͽ� ���� ���� �ִ밪�� ����Ѵ�.


2. Ǯ�� ��ȹ

1. ������ ���� K���� ��ġ�� �����ϴ� ������ �����ϵ�, ������ ĭ�� �������� �ʵ��� �湮 ǥ�ø� �����Ѵ�.
2. K���� ��ġ�� ��� �����Ͽ��� ���, �� ���� ���Ͽ� ��������� �ִ밪�� ���� �� �� ū ���� �����Ѵ�.


3. ��ȹ ����
 ������ ��ȯ��Ģ�� �����ϹǷ�, ���� ���ϴµ��� ������ �� ������ �������. => ���� ���վ˰����� ����Ͽ� K���� ���� �����Ͽ��� ��� ����� ���� ����� �� �ִ�.


*/

int M, N, K;
int grid[10][10];
int isPicked[100];

int solution(int index, int curSize, int curSum) {
	int maxNum = -10000 * M * N;

	if (curSize == K) {
		return curSum;
	}

	for (int i = index; i < M * N; i++) {
		int adjacentIndexDown = i + M;
		int adjacentIndexRight = i + 1;

		// ������ ĭ�� ���õ��� �ʾ��� ��쿡�� ���� �ܰ� ����
		if (isPicked[i] == 0) {


			// �ε����� ������ ����� ���� ���� ǥ��
			if (adjacentIndexDown < N * M) {
				isPicked[adjacentIndexDown]++;
			}
			// �� ��ġ�� ���� ������ ���� ��츦 �����ϰ� ������ ��ġ ǥ��
			if (adjacentIndexRight % M != 0) {
				isPicked[adjacentIndexRight]++;
			}

			maxNum = max(maxNum, solution(i + 1, curSize + 1, curSum + grid[i / M][i % M]));

			// ���󺹱�
			if (adjacentIndexDown < N * M) {
				isPicked[adjacentIndexDown]--;
			}
			if (adjacentIndexRight % M != 0) {
				isPicked[adjacentIndexRight]--;
			}
		}
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solution(0, 0, 0);
}