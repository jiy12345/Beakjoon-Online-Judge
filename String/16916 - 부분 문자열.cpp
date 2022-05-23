#include<vector>
#include<iostream>
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

string  S, P;

// KMP ����
// �����Լ� ����(���λ�� ���̻� �ִ� ��ġ ���� ��)
vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();

    vector<int> table(patternSize, 0);

    int j = 0;
    for (int i = 1; i < patternSize; i++) {

        // j �ε����� 0�̻��ε�, i��°�� j��° ���ڰ� ��ġ���� �ʴ´ٸ�, 
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1]; // �� ĭ �ڷ� �� 
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

int KMP(string S, string P) {
    vector<int> table = makeTable(P);
    int j = 0;

    for (int i = 0; i < S.length(); i++) {
        while (j > 0 && S[i] != P[j]) {
            j = table[j - 1];
        }
        if (S[i] == P[j]) {
            if (j == P.length() - 1) return 1;
            else j += 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    cin >> P;

    cout << KMP(S, P);
}