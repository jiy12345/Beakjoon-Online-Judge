#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<string>
using namespace std;



/*
1. ���� �м�

- ���� ���� ����
�� �̸��� ���� <= 30
�Էµ� ���� ���� �� <= 10,000
�Էµ� ������ �� �׷� �� <= 1,000,000

 - ���� ��Ȳ
 �־��� �� ���� �̸��� ���������� ����ϰ�, �� ���� �����ϴ� ������ ������� �Ҽ��� 4°�ڸ����� �ݿø��� �Բ� ���

2. Ǯ�� ��ȹ
�̸�(���ڿ�) �� ������ �����̹Ƿ� �� �ڷ����� �ٷ� ���ö���.

������ ���� ������ ��ġ��

1. ���ڿ��� �Է¹�����, �ش� ���ڿ��� �ش��ϴ� ���� 1 ������Ų��.
2. ���� ��� ������ ���� ���Ѵ�.
3. �� Ű�� ���� �� ������ 2������ ���� ������ ���� ���� ����Ѵ�.

3. ��ȹ ����


*/

void solution() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string temp = "";

	map<string, int> trees;

	while(getline(cin, temp)) {
		trees[temp]++;
	}

	float sum = 0;
	map<string, int>::iterator it;
	for (it = trees.begin(); it != trees.end(); ++it) {
		sum+=it->second;
	}

	cout << fixed;
	cout.precision(4);
	for (it = trees.begin(); it != trees.end(); ++it) {
		cout << it->first << " " << it->second / sum * 100 << "\n";
	}

}

int main() {


	solution();

	return 0;
}