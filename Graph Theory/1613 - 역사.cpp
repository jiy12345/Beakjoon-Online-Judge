#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
n: ���(���)�� ����
k: ���� ����(����)�� ����

s: ����� ���� ���踦 �˰� ���� ��� ���� ��

- ���� ���� ����
����� ��ȣ�� 1 ~ n

n: 1 ~ 400
k: 1 ~ 50,000

s: 1 ~ 50,000

����� ���� ���谡 ����� ���� ����.

- ���� ��Ȳ
 


2. Ǯ�� ��ȹ
 ���ͽ�Ʈ�� �˰����� ���� ����ؼ� �ּ� �ð��� ����ϵ�, �� �ܰ迡�� ����� �ʰ��Ǵ� ��δ� �������� �ʵ��� �Ѵ�!

3. ��ȹ ����
*/

#define MAX 401

int n, k, s;

int isComparable[MAX][MAX];

void floydWarshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (isComparable[i][k] != 0 && isComparable[i][k] == isComparable[k][j])
                    isComparable[i][j] = isComparable[i][k];
}

void solution() {
    floydWarshall();

    cin >> s;

    int a, b;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        cout << isComparable[a][b] << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;

        isComparable[a][b] = -1;
        isComparable[b][a] = 1;
    }

    solution();
}
