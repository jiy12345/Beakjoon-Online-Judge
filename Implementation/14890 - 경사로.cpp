#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
1. ���� �м�
- ����
N: ��, ���� ����
L: ������ ����

- ���� ���� ����
N: 2 ~ 100
L: 1 ~ N

- ���� ��Ȳ
 ������ �� �ִ� ���� ������ ���� ������ �������Ѿ� �Ѵ�.

 - �濡 ���� ��� ĭ�� ���̰� ����.
 - ��� ĭ�� ���̰� ���� �ʴٸ� ���η� �̾��� �־�� �Ѵ�.

 ���ΰ� ������ ���� ������ ������ ��ġ�Ǹ� ������ ������ ���ٰ� �� ��, 
 
 - ���δ� ���� ĭ�� ������, L���� ���ӵ� ĭ�� ������ �ٴ��� ��� ���ؾ� �Ѵ�.
 - ���� ĭ�� ���� ĭ�� ���� ���̴� 1�̾�� �Ѵ�.
 - ���θ� ���� ���� ĭ�� ���̴� ��� ���ƾ� �ϰ�, L���� ĭ�� ���ӵǾ� �־�� �Ѵ�.

 ������ �� �ִ� ���� ������ ���Ͽ���.

2. Ǯ�� ��ȹ

���� �ʿ��� ���� ������ �����ϸ�, ������ ������Ű�� ������ �� ����������(������ �� ���� ��) ��� ������ ������� ��� ������ �� �ִ� ��� �ϴ� ������ ����.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N, L;
int Map[100][100];

bool isPassableRow(int j) {
	bool isPassable = true;

	return isPassable;
}

bool isPassableColumn(int j) {
	bool isPassable = true;


	return isPassable;
}

bool isPassable(int i, int j) {
	if (i == 0) {
		return isPassableColumn(j);
	}
	else if (j == 0) {
		return isPassableRow(i);
	}
}
void solution(string command) {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer += isPassable(i, 0) ? 1 : 0;
		answer += isPassable(0, i) ? 1 : 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	return 0;
}