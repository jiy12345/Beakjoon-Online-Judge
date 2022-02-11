#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
1. ���� �м�
- ����
M: ������ ��
x: �ԷµǴ� ��

- ���� ���� ����
M: 1~3,000,000
x: 1~20

- ���� ��Ȳ
 ����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
remove x: S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
check x: S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
toggle x: S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
empty: S�� ���������� �ٲ۴�. 

 check ������ �־��� ������ ����� ����Ѵ�!

2. Ǯ�� ��ȹ

�������� ���� �����̴�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define ALL_NUM 1048575

int S;

map<string, int> commandMap = {
	{"add", 0},
	{"remove", 1},
	{"check", 2},
	{"toggle", 3},
	{"all", 4},
	{"empty", 5},
};

enum commandEnum { ADD, REMOVE, CHECK, TOGGLE, ALL, EMPTY };

void solution(string command) {
	int commandNum = commandMap[command];
	int inputNum;

	switch (commandNum) {
	case ADD:
		cin >> inputNum;
		// 1�� ��� �״��, 0�� ��� 1��
		S |= (1 << (inputNum - 1));
		break;	
	case REMOVE:
		cin >> inputNum;
		// 0�� ��� �״��, 1�� ��� 0����
		S &= ~(1 << (inputNum - 1));
		break;	
	case CHECK:
		cin >> inputNum;
		cout << ((S & (1 << (inputNum - 1))) >> (inputNum - 1)) << '\n';
		break;	
	case TOGGLE:
		cin >> inputNum;
		// 0�� ��� 1��, 1�� ��� 0����
		S ^= (1 << (inputNum - 1));
		break;	
	case ALL:
		S = ALL_NUM;
		break;	
	case EMPTY:
		S = 0;
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		string command;

		cin >> command;

		solution(command);

		// for debug
		//for (int i = 19; i >= 0; --i) {
		//	int result = S >> i & 1;
		//	printf("%d", result);
		//}
		//cout << endl;
	}

	return 0;
}