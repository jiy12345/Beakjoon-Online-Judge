#include<iostream>
#include<algorithm>
using namespace std;

/*
1. ���� �м�

- ����
N: �������� ����

- ���� ���� ����
N: 1~1,000
���� ����: 1~1,000,000

 - ���� ��Ȳ
 ���� �������� �־����� ��, �� �ߵ��� ����Ͽ� ������ �� ���� ���� ���� ���� �� �ּҰ��� ���Ͽ���

2. Ǯ�� ��ȹ
�̰� ��� �����ؾ� �ұ�?

�ߺ��ؼ� ���� �� ���� ������ ��� �����Ƿ� ���� �����̱� �ѵ�, �׷��ٰ� ��� ������ �� ���ϱ⿡�� 2^N���� ������ �ð����⵵�� ���̹Ƿ� �׷��� ���� ���� ����.

�׷��ٸ� ���?

������ ���¿��� �����պ��� ũ�ٸ�, 

Sn:

3. ��ȹ ����


*/


int N;
int weight[1000];


int solution() {
	sort(weight, weight + N);

	int cur_sum = 0;

	for (int i = 0; i < N; i++) {
		if (cur_sum + 2 <= weight[i]) {
			break;
		}

		cur_sum += weight[i];
	}
	
	return cur_sum + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	cout << solution()';

	return 0;
}