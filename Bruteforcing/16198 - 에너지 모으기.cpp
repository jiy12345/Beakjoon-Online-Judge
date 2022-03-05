#include<iostream>
#include<vector>
using namespace std;


/*
1. ���� �м�
- ����
Wi: i��° ������ ����

- ���� ���� ����
Wi: 1 ~ 1,000

- ���� ��Ȳ

������ ���� ��Ģ�� ���� �������� ���� �� �ִٰ� �� ��,

1. ������ ���� �ϳ��� ����. �� ������ ������ ��ȣ�� x��� �Ѵ�. ��, ù ��°�� ������ ������ ������ �� �� ����.
2. x��° ������ ������ �����Ѵ�.
3. Wx-1 �� Wx+1�� �������� ���� �� �ִ�.
4. N�� 1 ���ҽ�Ű��, ������ ������ 1������ N�������� �ٽ� ��ȣ�� �ű��. ��ȣ�� ù ������ 1��, ���� ������ 2��, ... �� ���� �Űܾ� �Ѵ�.

���� �� �ִ� ������ ���� �ִ��� ���Ͽ���

2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

int N;
vector<int> W;

int solution(int prevEnergy) {
	int maxNum = 0;
	if (W.size() == 2) {
		return prevEnergy;
	}

	for (int i = 1; i < W.size() - 1; i++) {
		int temp = W[i];
		W.erase(W.begin() + i);
		maxNum = max(maxNum, solution(prevEnergy + W[i - 1] * W[i]));
		W.insert(W.begin() + i, temp);
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		W.push_back(temp);
	}

	cout << solution(0);

	return 0;
}