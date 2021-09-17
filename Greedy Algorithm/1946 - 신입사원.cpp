#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�

 - ����
- �� ���� ������ �־�����.
- ������ 0~9, +, -�θ� �̷���� �ִ�.

 - ����, ���� ���� ����
- ���� ó���� ������ ���ڴ� �����̴�.
- �����ؼ� �� �� �̻��� �����ڴ� ��Ÿ���� �ʴ´�.
- 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����.
- ���� 0���� ������ �� �ִ�.
- ���� ���̴� 50���� �۰ų� ����

 - ���� ��Ȳ
 ������ �־����� ��, ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��϶�

2. Ǯ�� ��ȹ
������ ���ø� ���캸��, ������ ����� �ڸ��ų� �����ڸ� ��ȣó�� �����ؼ� �߶� ������ ����� ���� ���� ���δ�.

=> �׷��ٸ� ���� ����� �ٲ� �� �ִ� ���� - �� ��� �����Ŀ� �޷��ִ�. -�� ���� ���� �ִ밪�� �ǵ��� �ϸ�ȴ�.

 ù - �����ڸ� �߰��ߴٸ�, �� ���� ������ ��� ���� ������ �����ص� �ȴ�.

����

1. ���ڿ� ������ ���� �޴´�.
2. �� ���� �� ����, ù - �� ���� �� ������ ������ ���ϰ�, ù - ���Ŀ��� ������ ��� ����.

3. ��ȹ ����
ù - ������ ���� �� ���� ������ ��� ���� ������ �����ص� �Ǵ� ������ ������ ����.
 ù - ������ ���� + �����ڰ� ���´ٸ� ��� ��ȣ�� ���� ������ �����Ͽ� ��� ���� ������ ������ �� �ִ�.
 ù - ������ ���� - �����ڵ鸸 ���´ٸ� ���� ��ȣ�� ���� �ʾƵ� �ּҰ��� �����ȴ�.
 ù - ������ ���� + �����ڿ� - �����ڰ� ������ ���͵� + �����ڴ� ��� ������ ���Դ� - �����ڿ� ���� ��� ���� ������ ��ȯ�� �� �ִ�.

 ���� ���̴� 50 �����̹Ƿ� �ð��� ������ �־������ �ʾҴ�.

 */

int get_min_num(string expression) {
	int min_num = 0; // �ּҰ��� ������ ����
	int index;
	int i;

	// - �� ���� ��ūȭ
	string plus_expression = "";
	string minus_expression = "";

	i = expression.find('-');

	plus_expression = expression.substr(0, i);
	if (i != -1) {
		minus_expression = expression.substr(i + 1);
	}

	// 
	string temp_string = "";
	for (i = 0; i < plus_expression.size(); i++) {

		if (plus_expression[i] == '+' || plus_expression[i] == '-') {
			min_num += stoi(temp_string);
			temp_string = "";
		}
		else {
			temp_string += plus_expression[i];
		}
	}
	if (!temp_string.empty()) {
		min_num += stoi(temp_string);
		temp_string = "";
	}

	temp_string = "";
	for (i = 0; i < minus_expression.size(); i++) {

		if (minus_expression[i] == '+' || minus_expression[i] == '-') {
			min_num -= stoi(temp_string);
			temp_string = "";
		}
		else {
			temp_string += minus_expression[i];
		}
	}
	if (!temp_string.empty()) {
		min_num -= stoi(temp_string);
		temp_string = "";
	}

	return min_num;
}

int main() {

	string expression;

	cin >> expression;

	cout << get_min_num(expression);

	return 0;
}