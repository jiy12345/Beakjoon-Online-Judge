#include<iostream>
#include<map>

using namespace std;

/*
1. ���� �м�
- ����
N: ������ ���� ����
S: ��ǥ�� �ϴ� ��

- ���� ���� ����
N: 1 ~ 40
S: -1,000,000 ~ 1,000,000
������ ���Ե� ��: -100,000 ~ 100,000

- ���� ��Ȳ
 i��° ������ j��° �������� �� A[i] + A[i+1] + �� + A[j-1] + A[j]�� M�� �Ǵ� ����� ���� ���Ͽ���

2. Ǯ�� ��ȹ

�ϴ� 10,000�� �Է��� �ִ� ũ���̹Ƿ�, ������ ó������ ������ ���� �Ұ����ϴ�.

���� ���� ������ ���� ���ؾ� �ϴµ�, ���� �����̶�� ���� ��� ǥ���ұ�?

=> ���ĵǴ� �����̶�� �� ���� �ְڴ�.

3. ��ȹ ����


*/

enum FIRSTORSECOND { FIRST, SECOND };

int N, S;
int A[41];
map<int, int> subsum;
long long cnt;

void solution(int curIndex, int sum, int end, FIRSTORSECOND firstOrSecond) {
    if (curIndex == end) {
        // ù��° ���� �迭�� ���� �յ��� ���� ����س���
        if (firstOrSecond == FIRST) {
            // �ϳ��� ���� sum ��ü�� ���� ������
            subsum[sum]++;

            // �������� ��찡 �׻� ���ԵǹǷ�, subsum[0]�� 1�� �ȴ�.
        }
        else { // �ι�° ���� �迭�� ����� �� �� ���� ��
            // �ϳ��� ���� sum ��ü�� ����
            cnt += subsum[S - sum];

            
        }
        return;
    }

    // ���� ���� ������ ���
    solution(curIndex + 1, sum + A[curIndex], end, firstOrSecond);
    // ���� ���� �������� ���� ���
    solution(curIndex + 1, sum, end, firstOrSecond);
}

void meetInTheMiddle() {
    solution(0, 0, N / 2, FIRST);
    for (pair<int, int> i : subsum) {
        cout << "sum: " << i.first << ", numOfSum: " << i.second << endl;
    }
    solution(N / 2, 0, N, SECOND);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    meetInTheMiddle();

    // S�� 0�� ���, 
    // �ƹ��͵� ���� �ʾ��� �� ���� �ϳ��� ����� ���� ���ԵǹǷ� ���ֱ�
    if (!S) cout << cnt - 1;
    else cout << cnt;

    return 0;
}
