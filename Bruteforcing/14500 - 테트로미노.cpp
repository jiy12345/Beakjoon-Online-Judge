#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ���� ����
M: ������ ���� ����

- ���� ���� ����
N, M: 4~500
���̿� ���� ��: 1~1,000

- ���� ��Ȳ
 ������ ũ�Ⱑ �־�����, �� ���̿� �����ִ� ���� �־��� ��, 
 ��Ʈ�ι̳븦 ��ġ�Ͽ� ���� ĭ�� ������ ���� �ִ밪�� ���Ͽ��� 

 �� �ټ������� ��Ʈ�ι̳�� ��Ī, ȸ���� �����ϴ�.

2. Ǯ�� ��ȹ

1. �� ���: ���� ���� 2��
2. ���� ���: ȸ���� �� 4�� + ��Ī�Ͽ� ȸ���� �� 4��
3. �������: ȸ���� �� 2�� + ��Ī�Ͽ� ȸ���� �� 2��
4. �� ���: 4��
5. ���簢���: 1��


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N, M;

int paper[500][500];

bool isInRange(int i, int j) {
	if (0 <= i && i <= N - 1 && 0 <= j && j <= M - 1) return true;
	else return false;
}

int checkIMino(int i, int j) {
	int maxNum = 0;
	// ��
	// ��
	// ��
	// ��
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 2, j) && isInRange(i + 3, j)) 
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);
	// ��������
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i, j + 3)) 
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);
	
	return maxNum;
}


int checkOMino(int i, int j) {
	int maxNum = 0;

	// ����
	// ����
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1]);

	return maxNum;
}

int checkZMino(int i, int j) {
	int maxNum = 0;

	// ����
	//   ����
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2)) 
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
	//   ��
	// ����
	// ��
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 2][j]);

	return maxNum;
}

int checkSMino(int i, int j) {
	int maxNum = 0;

	//   ����
	// ����
	if (isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i, j + 1) && isInRange(i, j + 2))
		maxNum = max(maxNum, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2]);
	// ��
	// ����
	//   ��
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);

	return maxNum;
}
int checkJMino(int i, int j) {
	int maxNum = 0;

	//   ��
	//   ��
	// ����
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1) && isInRange(i + 2, j)) 
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j]);
	// ��
	// ������
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
	// ����
	// ��
	// ��
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j]);
	// ������
	//     ��
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2]);

	return maxNum;
}

int checkLMino(int i, int j) {
	int maxNum = 0;

	// ��
	// ��
	// ����
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 2, j) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1]);
	// ������
	// ��
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j]);
	// ����
	//   ��
	//   ��
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);
	//     ��
	// ������
	if (isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2) && isInRange(i, j + 2))
		maxNum = max(maxNum, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 2]);

	return maxNum;
}

int checkTMino(int i, int j) {
	int maxNum = 0;

	// ������
	//   ��
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1]);
	//   ��
	// ����
	//   ��
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1) && isInRange(i + 1, j))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 1][j]);
	//   ��
	// ������
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 1][j + 2]);
	// ��
	// ����
	// ��
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j]);

	return maxNum;
}

int solution() {
	int maxNum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			maxNum = max(maxNum, checkIMino(i, j));
			maxNum = max(maxNum, checkOMino(i, j));
			maxNum = max(maxNum, checkZMino(i, j));
			maxNum = max(maxNum, checkSMino(i, j));
			maxNum = max(maxNum, checkJMino(i, j));
			maxNum = max(maxNum, checkLMino(i, j));
			maxNum = max(maxNum, checkTMino(i, j));
		}
	}
	
	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	cout << solution();
}