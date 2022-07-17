#include<iostream>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
 N: ���� ����� ����

- ���� ���� ����
 N: 1 ~ 1,000

 BOJ�Ÿ��� �� ������Ͽ��� B, O, J �߿� �ϳ��� ���� �ִ�
 1���� �ݵ�� B�̴�

- ���� ��Ȳ
��ŸƮ�� ���� �ִ� ���� i���̶��, i+1������ N�������� ������ �� �� �ְ�, 
�� �� kĭ ��ŭ ������ �ϴµ� �ʿ��� �������� ���� k*k�̶�� �� ��,
��ŸƮ�� ��ũ�� �����µ� �ʿ��� ������ ���� �ּڰ��� ���Ͽ���.


2. Ǯ�� ��ȹ


1. �湮�� ������ ��ġ�� ����(����� ������ ���� 0�� �ƴ� ��ġ�� ����) ������ �ݺ��Ѵ�.
 1) �� ��ġ�� ������ġ���� �� ��ġ������ �� �ִ� ��ġ���� �� �ʿ��� ���������� ������ ���� �Ŀ� ���� ���Ѵ�.
  ���� ��ġ�� ������ �� = ���� ��ġ������ ������ �� + k * k
 2) 1)���� ���� ���� ���� ����Ǿ� �ִ� ������ ���� ���� �����ϰ�,�׷��� ������ �������� �ʴ´�.

3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/

#define MAX 1000

int dp[MAX];

int N;
string road;

char nextChar(char curChar) {
	switch (curChar)
	{
	case 'B':
		return 'O';
	case 'O':
		return 'J';
	case 'J':
		return 'B';
	}
}

int solution() {
	fill(&dp[1], &dp[N], MAX * MAX);

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			// ���� ������ ����
			if (road[j] == nextChar(road[i]))
				dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));

	return (dp[N - 1] == MAX * MAX) ? -1 : dp[N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> road;

	cout << solution();
}