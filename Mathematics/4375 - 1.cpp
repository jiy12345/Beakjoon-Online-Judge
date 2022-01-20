#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
n: ������ �� ��

- ���� ���� ����
n: 1~10,000

- ���� ��Ȳ
 2�� 5�� ������ �������� �ʴ� ���� n�� �־����� ��, 1�θ� �̷���� n�� ����� ã�ƶ�

2. Ǯ�� ��ȹ
 10�� ���ذ��� ������ ������������ �˻��ϸ� �� �� �ϴ�.
 
 n�� 2�� 5�� ������ �������� �ʾƾ� �ϴ� ������, n�� 2�� 5�� ������ ������ ��� 1�� �ڸ����� 1�� ���� ���� ���� �� ���� �����̴�.



3. ��ȹ ����

*/

int solution(int n) {
    int cnt = 1;
    int ones = 1;

    while (true) {
        ones %= n;
        if (ones == 0) {
            break;
        }

        // �ڸ��� ����
        cnt++;

        // 1�Ѱ� �߰�
        ones *= 10;
        ones++;

    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;

    while (getline(cin, n)) {
        cout << solution(stoi(n)) << '\n';
    }

    return 0;
}
