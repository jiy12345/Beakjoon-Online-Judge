#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
1. 문제 분석

- 변수
t: 테스트 케이스의 개수
n: 전화번호의 수

- 변수 제한 사항
t: 1~50
n: 1~10,000

 - 문제 상황
 전화번호 목록이 일관성이 있다는 것은, 한 번호가 다른 번호의 접두어인 경우가 없다는 의미이다.

 전화번호 목록이 주어졌을 때, 해당 전화번호 목록이 일관성 있는 목록인지를 구하여라.

2. 풀이 계획
 에라토스테네스의 체를 활용하되, 각 수의 제곱 수로 진행해야 할 듯 하다!


3. 계획 검증


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