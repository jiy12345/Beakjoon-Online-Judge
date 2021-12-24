#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
1. ���� �м�

- ����
t: �׽�Ʈ ���̽��� ����
n: ��ȭ��ȣ�� ��

- ���� ���� ����
t: 1~50
n: 1~10,000

 - ���� ��Ȳ
 ��ȭ��ȣ ����� �ϰ����� �ִٴ� ����, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ���ٴ� �ǹ��̴�.

 ��ȭ��ȣ ����� �־����� ��, �ش� ��ȭ��ȣ ����� �ϰ��� �ִ� ��������� ���Ͽ���.

2. Ǯ�� ��ȹ
 �����佺�׳׽��� ü�� Ȱ���ϵ�, �� ���� ���� ���� �����ؾ� �� �� �ϴ�!


3. ��ȹ ����


*/




string solution(string *phoneBook, int n) {
	sort(phoneBook, phoneBook + n);

	for (int i = 1; i < n; i++) {
		if (phoneBook[i - 1] == phoneBook[i].substr(0, phoneBook[i - 1].size())) {
			return "NO";
		}
	}

	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string phoneBook[10000];

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> phoneBook[j];
		}

		cout << solution(phoneBook, n) << '\n';
	}

	return 0;
}