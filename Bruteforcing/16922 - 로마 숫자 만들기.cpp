#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N: ����� �� �ִ� ������ ����

- ���� ���� ����
N: 1 ~ 20
I, V, X, L�� ����Ѵ�. �� ���ڴ� 1, 5, 10, 50�� �ǹ�

- ���� ��Ȳ
���ڿ��� ��Ÿ���� ����, �� ���ڰ� �ǹ��ϴ� ���� ��� ���� ���̶� �� ��,

�θ� ���� N���� ����Ͽ� ���� �� �ִ� ���� �ٸ� ���� ������ ����϶�

2. Ǯ�� ��ȹ
 �ߺ� ���� ������ �� �� �ִ�.
 
 => ������ ������ �� ���ϴ� ���̹Ƿ�, ������ ������ ��ȯ��Ģ�� �����ϹǷ�, ���� ������ �ٸ� ��츦 ������� �ʾƵ� �ȴ�!

 ���� ��� ���� �ߺ��ǵ��� N���� ���� ���� ��, ���� ���� üũ�ϱ� ���� �湮 ǥ�ø� �����ϸ� �� �� �ϴ�.
  => ���ü� �ִ� ���� �ִ밪�� 50(L) x 20(N�� �ִ밪) = 1,000�̹Ƿ�, 1,000ũ���� �迭�� ����� üũ�ϸ� �� �� �ϴ�.

3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/

int N;

int romanNum[4] = { 1, 5, 10, 50 };
bool isVisited[20 * 50 + 1];

int perm_comb(int curIndex, int curPicked, int curSum) {
	int answer = 0;
	if (curPicked == N) {
		if (isVisited[curSum] == false) {
			isVisited[curSum] = true;
			return 1;
		}
		return 0;
	}

	for (int i = curIndex; i < 4; i++) {
		answer += perm_comb(i, curPicked + 1, curSum + romanNum[i]);;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << perm_comb(0, 0, 0);
}