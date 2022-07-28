#include<iostream>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� B�� ũ��


- ���� ���� ����
Bi: 1 ~ 10^9
N: 1 ~ 10^5


- ���� ��Ȳ
�� �� A, B�� �־�����, ������ ������ ������ ���ٰ� �� ��,

2�� ���Ѵ�.
1�� ���� ���� �����ʿ� �߰��Ѵ�.

A�� B�� �ٲٴµ� �ʿ��� ������ �ּҰ��� ���Ͽ���.
�ٲ� �� ���� ��� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ

1. bfs�� �����ϵ�

�湮 ǥ�ø� bool������ �����ϸ� 1�Ⱑ����Ʈ�� �ʿ��ϴ�. ��� ó���� �� ������?

- ���� 1: ��Ʈ ���� <<�� ���� ����
=> ���� 1�� ����� �׻� ¦���̴�.
- ���� 2: ���� 10�� ���� �� 1 ���ϴ� ������ ���� ����
=> ���� 2�� ����� �׻� Ȧ���̴�.

=> ������ �� ������ ��� ���� Ŀ���� �����̹Ƿ�, B�̻����� ������ �ʿ䰡 ����.



3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/

#define MAX 1000000000

int N, B[100000], ans = MAX;

void dfs(int prevValue, int idx, int cnt, int r) {
	if (cnt >= ans) return;
	if (idx >= N) {
		ans = min(cnt, ans);
		return;
	}
	if (B[idx] - prevValue == r) dfs(B[idx], idx + 1, cnt, r);
	if (B[idx] - 1 - prevValue == r) dfs(B[idx] - 1, idx + 1, cnt + 1, r);
	if (B[idx] + 1 - prevValue == r) dfs(B[idx] + 1, idx + 1, cnt + 1, r);
}

int solution() {
	// ������ ���� ���ڿ� ������ ���� �ݺ�
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			dfs(B[1] + i, 2, (i != 0) + (j != 0), (B[1] + i) - (B[0] + j));
	
	return (ans != MAX) ? ans : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> B[i];

	cout << solution();
}