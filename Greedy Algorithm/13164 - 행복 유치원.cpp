#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� A�� ũ��

- ���� ���� ����
N:1~1,000,000

������ �̷�� �ִ� ��: 1 ~ 1,000,000

- ���� ��Ȳ
�� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� 1,000,000,009�� ���� �������� ���

2. Ǯ�� ��ȹ

������ �Ǵ� ��: ������ ����� ���� �ѹ��� ��� ��Ÿ�� ���̳�?

�� ��ġ������ ���� ������

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] �̾�� �ϳ�, �� ���ǿ� ���� �� ���������� �Ѵ�!

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define MAX 300000

int N, K;
int height[MAX];

int solution() {
    int answer = 0;

    vector<int> diff(N - 1);
    for (int i = 0; i < N - 1; i++)
        diff[i] = height[i + 1] - height[i];

    sort(diff.begin(), diff.end(), greater<int>());

    for (int i = K - 1; i < diff.size(); i++)
        answer += diff[i];

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> height[i];

    cout << solution() << endl;

    return 0;
}