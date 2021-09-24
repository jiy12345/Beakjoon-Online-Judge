#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string vowel = "aeiou";

/*
1. ���� �м�

- ����
L: ��ȣ�� ����
C: ���� ������ ����

- ���� ����
3 <= L <= C <= 11

- ���� ��Ȳ
���ĺ��� ��ȣ ������ �׻� �����ϴ� ������ �迭�Ǿ�� �Ѵ�.
��ȣ�� �ּ� �� ���� ������ �� ���� �������� �����Ǿ� �־�� �Ѵ�.
�� ��, ������ ��� ��ȣ�� ����Ѵ�.

2. Ǯ�� ��ȹ
�ϳ��� ����: ���ĺ� �ϳ� ����

- ���� ���: L���� ���ĺ� ����

�ϴ� �����ϴ� �����̹Ƿ� ������ �̷������ �� �� ����.

=> ���� �ܰ迡�� ������ ���ĺ��� �����ܰ� ���� ���ĺ����� C-�̾ƾ��� ���ĺ�(L-cypher.size)

*/

void solution(int L, int C, vector<char> alpha, string cypher, int cur_index, int num_vowel, int num_consonent) {
	int cur_size = cypher.size();
	if (cur_size == L) {
		// ������ ������ų ��쿡�� ���
		if (num_vowel >= 1 && num_consonent >= 2) {
			cout << cypher << endl;
		}
		return;
	}

	for (int i = cur_index;i < C - (L - cur_size) + 1;i++) {
		if (vowel.find(alpha[i]) == string::npos) { // ������ ���
			solution(L, C, alpha, cypher + alpha[i], cur_index + (i - cur_index) + 1, num_vowel, num_consonent + 1);
		}
		else { // ������ ���
			solution(L, C, alpha, cypher + alpha[i], cur_index + (i - cur_index) + 1, num_vowel + 1, num_consonent);
		}
	}
	;
}

int main() {
	int L, C;
	char temp;
	cin >> L >> C;

	vector<char> alpha;

	for (int i = 0;i < C;i++) {
		cin >> temp;
		alpha.push_back(temp);
	}

	sort(alpha.begin(), alpha.end());

	solution(L, C, alpha, "", 0, 0, 0);

	return 0;
}