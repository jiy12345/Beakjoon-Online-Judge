#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
n: ������ ���� ������ ����

- ���� ���� ����
n:1~100,000
������ ���� ��: -1,000~1,000

- ���� ��Ȳ
 n���� ���� ���� ������ �־����� ��, ���ӵ� ��� ���� �����Ͽ� ���� �� �ִ� �� �� ���� ū ���� ���Ͽ���.
 �� ��, ���ӵ� �� �� �� ���� ���ܵ� �� �ִ�.

2. Ǯ�� ��ȹ
 ���� ���� ������ �հ� ���� �� ������ ���� ���� �����ϴ°� ���� �� �ϴ�!

 ���� ���� ������ �ִ밪


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define NOT_REMOVED 0
#define REMOVED 1
// ���� ��ġ�� ���� �����ϴ� ���� ���� �ִ밪
int dp[100000][2];
int sequence[100000];

int solution(int n) {

	dp[0][NOT_REMOVED] = sequence[0]; // ���� ù ��ġ�� �ڱ� �ڽŹۿ� �����Ƿ�
	dp[0][REMOVED] = sequence[0]; // ���� ù ��ġ�� �ڱ� �ڽŹۿ� �����Ƿ�

	int answer = dp[0][NOT_REMOVED];

	for (int i = 1; i < n; i++) {
		dp[i][NOT_REMOVED] = max(dp[i - 1][NOT_REMOVED] + sequence[i], sequence[i]);
		//                   ���� ���� �����ϴ� ���  / ���� ���� �������� �ʴ� ���
		dp[i][REMOVED] = max(dp[i - 1][NOT_REMOVED], dp[i - 1][REMOVED] + sequence[i]);
	
		answer = max(answer, max(dp[i][NOT_REMOVED], dp[i][REMOVED]));
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	cout << solution(n);

	return 0;
}