#include<iostream>
#include<vector>
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

// ���� �Է¹��� �迭
int A[1000000];
int index[1000000];

int N; // ������ ����

void solution() {

    vector<int> LIS;

    LIS.push_back(A[0]);
    index[0] = 1;

    for (int i = 1; i < N; i++) {
        // �� ��ġ�� ���� ���� ������� LIS�� ��� ������ ū ���� ���
        if (LIS.back() < A[i]) {
            LIS.push_back(A[i]);
            index[i] = LIS.size();
        }
        else { // �� ��ġ�� ������ �� ū ���� LIS�� ���� ���
            auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *it = A[i];
            index[i] = it - LIS.begin() + 1;
        }
    }

    cout << LIS.size() << '\n';

    vector<int> answer(LIS.size());
    int cnt = LIS.size();
    for (int i = N - 1; i >= 0; i--) {
        if (index[i] == cnt) {
            answer[cnt - 1] = A[i];
            cnt--;
        }
    }

    for (int i = 0; i < LIS.size(); i++) {
        cout << answer[i] << " ";
    }
}

class E {
public:
    int e[30];

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //cin >> N;

    //for (int i = 0; i < N; i++) {
    //    cin >> A[i];
    //}

    E e;
    
    e.e[3] = 10;

    E f;
    f = e;

    cout << f.e[3];

    //solution();
}