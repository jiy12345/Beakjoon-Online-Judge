#include<iostream>
#include<string>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ��
k: ������ �˾ƾ� �ϴ� �ڸ���

- ���� ���� ����
1 �� N �� 100,000,000  
1 �� k �� 1,000,000,000


- ���� ��Ȳ
 N�� k�� �־����� ��, ������� ���ڿ��� k��° �ڸ� ���� ����Ѵ�.
 ���� ���̰� k���� �۾Ƽ� k��° �ڸ� ���ڰ� ���� ���� -1�� ����Ѵ�.

2. Ǯ�� ��ȹ

�ϴ�, � �������� Ȯ���ؾ� �Ѵ�.
���� ���� �ø��� ����غ���

�� �ڸ����� ���� ������ ���ڴ� ������ ����.

(10^N - 10^(N-1)) * N

���� ���� ���� k���� ������


3. ��ȹ ����
 1. �˰��� ����

 2. �ð����⵵ ����

 3. �������⵵ ����
*/

int N, k;

int solution() {
    int answer = 0;
    int digit = 1;
    int tenSquared = 1;

    while (k > digit * tenSquared * 9) {
        k -= (digit * tenSquared * 9);
        answer = answer + tenSquared * 9;
        digit++;
        tenSquared *= 10;
    }


    // ���° �������� ���ϱ�
    answer = (answer + 1) + (k - 1) / digit;

    //cout << answer << endl;

    return (answer > N) ? -1 : (to_string(answer)[(k - 1) % digit] - '0');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;

	cout << solution();
}