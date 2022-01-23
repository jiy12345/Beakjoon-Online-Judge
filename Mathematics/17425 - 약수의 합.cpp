#include<iostream>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: �־����� �ڿ���

- ���� ���� ����
N: 1~1,000,000

- ���� ��Ȳ

f(A): �ڿ��� A�� ����� ��

g(x): x���� �۰ų� ���� ��� �ڿ��� y�� f(y)�� ���� ��

2. Ǯ�� ��ȹ

��� ���� ����� ���ؾ� �ϴµ� ��...

3. ��ȹ ����

*/

int N, T;
int X[100000];
long long FY[1000001];
long long FX[1000001];

void solution(int N) {
    // 1�� ��� ���� ����ϱ� ���� �־��ش�.
    fill_n(FX, N + 1, 1);
    /*
    ��� ���̵��. (i*1, i*2, i*3....)
    i�� 2���� n���� i�� ����� ���� ��� ����.
    �ð����⵵�� NlgN�̴�.
    j�� i*j������ �ݺ��Ѵ�. ���� ��� i�� 2�� ��� j�� ���ʸ������� ����ȴ�.
    2 * ���ʸ��� �鸸�̴ϱ�.
    */
    for (int i = 2; i < N; i++) {
        for (int j = 1; i * j < N+1; j++) {
            FX[i * j] += i;
        }
    }
    for (int i = 1; i <= N; i++) {
        FY[i] = FY[i - 1] + FX[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> X[i];
    }

    int max_num = *max_element(X, X + T);

    cout << max_num;
    solution(max_num);

    for (int i = 0; i < T; i++) {
        cout << "?";
        cout << FY[X[i]] << endl;
    }

    return 0;
}
