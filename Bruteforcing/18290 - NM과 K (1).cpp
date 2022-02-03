#include<iostream>
#include<vector>
#include<cstring>
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

- ���� ��Ȳ
 NxM ���ڿ� ������ ���� �� K���� ���� �����Ͽ� ���� ���� �ִ밪�� ����Ѵ�.


2. Ǯ�� ��ȹ

1. ������ ���� K���� ��ġ�� �����ϴ� ������ �����ϵ�, ������ ĭ�� �������� �ʵ��� �湮 ǥ�ø� �����Ѵ�.
2. K���� ��ġ�� ��� �����Ͽ��� ���, �� ���� ���Ͽ� ��������� �ִ밪�� ���� �� �� ū ���� �����Ѵ�.


3. ��ȹ ����
 ������ ��ȯ��Ģ�� �����ϹǷ�, ���� ���ϴµ��� ������ �� ������ �������. => ���� ���վ˰����� ����Ͽ� K���� ���� �����Ͽ��� ��� ����� ���� ����� �� �ִ�.


 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int M, N, K;
int grid[10][10];
bool isPicked[100];

int solution(int index, int curSize, int curSum, bool* isPicked) {
	int maxNum = -10000 * M * N;

	if (curSize == K) {
		return curSum;
	}

	for (int i = index; i < M * N; i++) {
		int adjacentIndexDown = i + M;
		int adjacentIndexRight = i + 1;

		// ������ ĭ�� ���õ��� �ʾ��� ��쿡�� ���� �ܰ� ����
		if (isPicked[i] == false) {
			bool isPickedTemp[100];

			memcpy(isPickedTemp, isPicked, sizeof(bool) * M * N);

			// �ε����� ������ ����� ���� ���� ǥ��
			if (adjacentIndexDown < N * M) {
				isPickedTemp[adjacentIndexDown] = true;
			}

			// �� ��ġ�� ���� ������ ���� ��츦 �����ϰ� ������ ��ġ ǥ��
			if (adjacentIndexRight % M != 0) {
				isPickedTemp[adjacentIndexRight] = true;
			}

			maxNum = max(maxNum, solution(i + 1, curSize + 1, curSum + grid[i / M][i % M], isPickedTemp));
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

	cout << solution(0, 0, 0, isPicked);
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

	cout << solution(0, 0, 0, isPicked);
}