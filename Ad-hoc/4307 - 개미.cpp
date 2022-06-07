#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
l: ������ ����
n: ������ ��

- ���� ���� ����
1 �� n �� 100,000
1 �� l �� 1,000,000
������ ��ġ�� ����
0 �� ������ ��ġ �� l


- ���� ��Ȳ
�� �׽�Ʈ ���̽��� ���ؼ� ���̰� ��� ������ �������� ������ �ð��� ���� ���� �ð�, ���� ���� �ð��� ����Ѵ�.
2. Ǯ�� ��ȹ

������ �Ǵ� ��: ������ ����� ���� �ѹ��� ��� ��Ÿ�� ���̳�?

�� ��ġ������ ���� ������

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] �̾�� �ϳ�, �� ���ǿ� ���� �� ���������� �Ѵ�!

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int t;
int n, l;

void solution() {
    int maxTime = 0;
    int minTime = 0;

    int location;
    for (int i = 0; i < n; i++) {
        cin >> location;

        minTime = max(minTime, min(location, l - location));
        maxTime = max(maxTime, max(location, l - location));
    }

    cout << minTime << " " << maxTime << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> l >> n;
        solution();
    }
}