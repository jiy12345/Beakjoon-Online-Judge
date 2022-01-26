#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����/���� ����

 - ������ ����
  C: ������
  P: �Ķ���
  Z: �ʷϻ�
  Y: �����
- ���� ���� ����
N: 3~50


- ���� ��Ȳ

������ ���� ��Ģ�� ���� ������ �Դ´ٰ� �� ��,

 ������ ���� ���δٸ� ������ �� ĭ�� �� ��, �� ĭ�� ����ִ� ������ ���� ��ȯ�� ��
 ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ��� �� ���� ������ ��� �Դ´�.

������ ä���� ���°� �־����� ���� �� �մ� ������ �ִ� ������ ����Ѵ�.

2. Ǯ�� ��ȹ
 �ٲ��� ���� ���¿��� �ִ밪�� ���� �� �����Ƿ�, �ϴ� �ٲ��� ���� ���¿����� �ִ밪�� ���� ����Ѵ�.

 �� �Ŀ��� ��� ��ġ�� ���ؼ� �˻縦 �����ϸ�, �����ʰ� �Ʒ��������� �񱳸� �����Ͽ� �ٸ���쿡�� ������ �ݺ��Ѵ�.

 1. �� ��ġ�� ������ ���� ��ȯ�Ѵ�.
 2. ������ ���� �� �ִ� �� Ȥ�� ���� ��� �˻��Ѵ�.
 
 �ٲٰ� �� ���� �� ��� �ϳ��� ��, Ȥ�� �ϳ��� ��� �ΰ��� ���� ���ؼ��� �˻縦 �����Ѵ�.



3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N;
string Candy[50];
char Colors[4] = { 'C', 'P', 'Z', 'Y'};

void swap(char&a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

int crossCheck(int rowAndColumnNum, char Color) {
	int maxNum = 0;
	int cntRow = 0;
	int cntColumn = 0;
	for (int k = 0; k < N; k++) {
		if (Candy[rowAndColumnNum][k] == Color) {
			cntRow++;
		}
		else {
			maxNum = max(maxNum, cntRow);
			cntRow = 0;
		}
		if (Candy[k][rowAndColumnNum] == Color) {
			cntColumn++;
		}
		else {
			maxNum = max(maxNum, cntColumn);
			cntColumn = 0;
		}
	}
	maxNum = max(maxNum, cntRow);
	maxNum = max(maxNum, cntColumn);

	return maxNum;
}

int solution() {
	int maxNum = 0;

	// �ƹ��͵� �ٲ��� �ʾ��� �� üũ
	// ��� ���� ���� �ݺ�
	for (int i = 0; i < 4; i++) {
		// ��� �� ���ÿ� üũ
		for (int j = 0; j < N; j++) {
			maxNum = max(maxNum, crossCheck(j, Colors[i]));
		}
	}
	
	// �� Ŀ�� ���� �����Ƿ�
	if (maxNum == N) {
		return N;
	}

	// �ٲ� �� �ִ� ��� ��ġ���� üũ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ������ �� ��ǥ�� �ƴ϶�� �����ʰ��� ��ȯ ����
			if (j != N - 1) {
				// �����ʰ� ��ȯ
				if (Candy[i][j] != Candy[i][j + 1]) {
					// ��ȯ
					swap(Candy[i][j], Candy[i][j + 1]);

					// ��� ���� ���� �ݺ�
					for (int k = 0; k < 4; k++) {
						// �ִ밪�� ������ ���� �� �ִ� ��ġ�� ���ؼ��� üũ
						maxNum = max(maxNum, crossCheck(i, Colors[k]));
						maxNum = max(maxNum, crossCheck(j, Colors[k]));
						maxNum = max(maxNum, crossCheck(j + 1, Colors[k]));
					}

					// ���󺹱�
					swap(Candy[i][j], Candy[i][j + 1]);
				}
			}

			// �Ʒ��� �� ��ǥ�� �ƴ϶�� �Ʒ��ʰ��� ��ȯ ����
			if (i != N - 1) {
				// �Ʒ��ʰ� ��ȯ
				if (Candy[i + 1][j] != Candy[i][j]) {
					// ��ȯ
					swap(Candy[i + 1][j], Candy[i][j]);

					// ��� ���� ���� �ݺ�
					for (int k = 0; k < 4; k++) {
						// �ִ밪�� ������ ���� �� �ִ� ��ġ�� ���ؼ��� üũ
						maxNum = max(maxNum, crossCheck(i, Colors[k]));
						maxNum = max(maxNum, crossCheck(i + 1, Colors[k]));
						maxNum = max(maxNum, crossCheck(j, Colors[k]));
					}

					// ���󺹱�
					swap(Candy[i + 1][j], Candy[i][j]);
				}
			}

			// �� Ŀ�� ���� �����Ƿ�
			if (maxNum == N) {
				return N;
			}
		}
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> Candy[i];
	}

	cout << solution();

}