#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ũ��

- ���� ���� ����
N: 1~64


- ���� ��Ȳ
�־��� ������ ��� 0���� �Ǿ� �ִٸ� ���� ����� 0����, ��� 1�� �Ǿ� �ִٸ� ���� ����� 1�� ������ �� �ִٰ� �ϸ�,
0�� 1�� ���� �ִٸ� �� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ�, �̷��� 4���� �������� ������ �����ϰ� �Ǹ�, �� 4���� ������ ������ ����� ���ʴ�� ��ȣ �ȿ� ��� ǥ���ؾ� �Ѵٰ� �� ��,

�־��� ������ ������ ����� ����ϴ� ������ ����ϴ� ���α׷��� �ۼ��϶�!

2. Ǯ�� ��ȹ
 ��������� ȣ���� �����Ͽ�, �� ��ġ�� ������ ������ �� ��ġ���� ����ϸ� �� �� �ϴ�!

 => �̶�, �Ѱ������ �Ű�������, ������ǥ�� ���� ���������� �� �� �ϴ�!
*/

string image[64];
int N;


void solution(int start_i, int start_j, int size) {
	if (size == 1) {
		cout << image[start_i][start_j];
		return;
	}

	char cur_num = image[start_i][start_j];

	int i, j;

	for (i = start_i;i < start_i + size;i++) {
		//cout << i << ": ";
		for (j = start_j;j < start_j + size;j++) {
			//cout << image[i][j];
			if (cur_num != image[i][j]) {
				break;
			}
		}
		//cout << endl;
		if (j != start_j + size) {
			break;
		}
	}

	// ���� ������ �̹����� ��� ���� ���� ������ ���� ���!
	if ((i == start_i + size) && (j == start_j + size)) {
		cout << cur_num;
	}
	else { // ���� ������ �̹����� 0�� 1�� ��� �����ϴ� ���
		cout << "(";
		// ���� ��
		solution(start_i, start_j, size / 2);
		// ������ ��
		solution(start_i, start_j + size / 2, size / 2);
		// ���� �Ʒ�
		solution(start_i + size / 2, start_j, size / 2);
		// ������ �Ʒ�
		solution(start_i + size / 2, start_j + size / 2, size / 2);
		cout << ")";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> image[i];
	}

	solution(0, 0, N);

}