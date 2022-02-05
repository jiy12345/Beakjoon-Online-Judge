#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
k: �ε�ȣ�� ����

- ���� ���� ����
k: 2~9

- ���� ��Ȳ
 ���õ� �ε�ȣ���踦 �����ϴ� k+1�ڸ��� �ִ�, �ּ� ������ ���� ����Ѵ�!

2. Ǯ�� ��ȹ
 �������� ���������̴�. ��ͷ� �����ϸ� �ɵ� �ϴ�.

 ���չ����� ���� �̹� ������ �� ���ķθ� �����ϹǷ� �����ߴ��� ���θ� ���� �ʿ䰡 �����µ�, ������ ��� �ұ�?


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define FORWARD true
#define BACKWARD false

int k;
bool inEqualitySigns[9];
int isPicked[10];

string minNum = "999999999";
string maxNum = "0";

// curOrder: ���� ���° ������ �̾Ҵ���
// prevNum: ������ ���� ��
void solution(int curOrder, int prevNum, string resultNum) {
	//cout << "curOrder: " << curOrder;
	//cout << ", inEqualitySigns[curOrder]: " << inEqualitySigns[curOrder];
	//cout << ", resultNum: " << resultNum << '\n';
	if (curOrder == k) {
		minNum = min(minNum, resultNum);
		maxNum = max(maxNum, resultNum);
		return;
	}

	if (inEqualitySigns[curOrder] == FORWARD) {
		for (int curNum = prevNum + 1; curNum <= 9; curNum++) {
			if (isPicked[curNum] == false) {
				isPicked[curNum] = true;
				solution(curOrder + 1, curNum, resultNum + to_string(curNum));
				isPicked[curNum] = false;
			}
		}
	}
	else {
		for (int curNum = prevNum - 1; curNum >= 0; curNum--) {
			if (isPicked[curNum] == false) {
				isPicked[curNum] = true;
				solution(curOrder + 1, curNum, resultNum + to_string(curNum));
				isPicked[curNum] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++) {
		char inEqualitySign;
		cin >> inEqualitySign;

		inEqualitySigns[i] = (inEqualitySign == '<') ? true : false;
	}

	for (int curNum = 0; curNum <= 9; curNum++) {
		isPicked[curNum] = true;
		solution(0, curNum, to_string(curNum));
		isPicked[curNum] = false;
	}

	cout << maxNum << '\n';
	cout << minNum;
}