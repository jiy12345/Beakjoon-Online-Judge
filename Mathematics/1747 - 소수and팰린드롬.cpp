#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ �� ��

- ���� ���� ����
N: 1~1,000,000

 - ���� ��Ȳ
 � �� N�� ����, N���� ũ�ų� ����, �Ҽ��̸鼭 �Ӹ������ �� �߿� ���� ���� ���� ���Ͽ���

2. Ǯ�� ��ȹ
 �Ҽ��� ���ϱ� ���ؼ��� ����ؼ� �Ҽ��� ���ϸ� vector�� �߰��ϰ�, N�̻��� �����ʹ� �縰��� �������� üũ�Ͽ� ���������� �� �� �ϴ�!


3. ��ȹ ����


*/

bool isPrime[1003002];

bool isPalindrome(string cur_num) {
	string cur_num_not_reversed = cur_num;
	reverse(cur_num.begin(), cur_num.end());
	string cur_num_reversed = cur_num;

	if (cur_num_not_reversed == cur_num_reversed) {
		return true;
	}
	else {
		return false;
	}
}

int solution(int N) {
	if (N <= 2) {
		return 2;
	}

	for (int i = 2; i <= 1003001; i++)
		isPrime[i] = true;


	for (int i = 2; i * i <= 1003001; i++)
	{
		if (isPrime[i])
			for (int j = i * i; j <= 1003001; j += i)
				isPrime[j] = false;
	}

	for (int i = N; i <= 1003001; i++) {
		// �Ӹ���� ���� ��� ����������
		if (isPalindrome(to_string(i)) && isPrime[i]) {
			return i;
		}
	}
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}